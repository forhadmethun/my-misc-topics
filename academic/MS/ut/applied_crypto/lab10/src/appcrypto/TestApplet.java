package appcrypto;

import javacard.framework.*;
import javacard.security.*;
import javacardx.crypto.Cipher;

// took 8.0 hours (please specify here how much time your solution required)

public class TestApplet extends Applet {
	Cipher rsa = Cipher.getInstance(Cipher.ALG_RSA_NOPAD, false);
	private KeyPair keypair ;
	private RSAPublicKey pub = null;
	private RSAPrivateCrtKey priv = null;
	byte[] tbuf = JCSystem.makeTransientByteArray((short)256, JCSystem.CLEAR_ON_DESELECT), dbuf = JCSystem.makeTransientByteArray((short)256, JCSystem.CLEAR_ON_DESELECT);
	MessageDigest messageDigest = MessageDigest.getInstance(MessageDigest.ALG_SHA_256, false);
	private final byte[] sha256Prefix = { (byte) 0x30, (byte) 0x31, (byte) 0x30, (byte) 0x0d, (byte) 0x06, (byte) 0x09, (byte) 0x60, (byte) 0x86,(byte) 0x48, (byte) 0x01, (byte) 0x65, (byte) 0x03,(byte) 0x04, (byte) 0x02, (byte) 0x01, (byte) 0x05,(byte) 0x00, (byte) 0x04, (byte) 0x20};
//	RandomData rnd;

	public static void install(byte[] ba, short ofs, byte len) {
		(new TestApplet()).register();
	}

	public void process(APDU apdu) {
		byte[] buf = apdu.getBuffer(); // contains first 5 APDU bytes
		switch (buf[ISO7816.OFFSET_INS]) {
//			case (byte)0x00:
//				if (buf[ISO7816.OFFSET_LC] != (byte)1) {
//					ISOException.throwIt(ISO7816.SW_DATA_INVALID);
//				}
//				apdu.setIncomingAndReceive(); // read APDU data bytes
//				short len = (short)(buf[ISO7816.OFFSET_CDATA] & (short)0xff); // get rid of sign
//				rnd = RandomData.getInstance(RandomData.ALG_SECURE_RANDOM);
//				rnd.generateData(buf, (short)0, len);
//				apdu.setOutgoingAndSend((short)0, len); // return response data
//				return;
			//generate rsa key
			case (0x02):
//				if(pub == null && priv == null){
					if(keypair == null) {
						keypair = new KeyPair(KeyPair.ALG_RSA, KeyBuilder.LENGTH_RSA_2048);
						keypair.genKeyPair();
						pub = (RSAPublicKey) keypair.getPublic();
					}
//					priv = (RSAPrivateCrtKey) keypair.getPrivate();
//				}
				return;
			//e
			case (0x04):
				apdu.setOutgoingAndSend((short)0, pub.getExponent(buf, (short)0));
				return;
			//n
			case (0x06):
				apdu.setOutgoingAndSend((short)0, pub.getModulus(buf, (short)0));
				return;
			//message decryption
			case (0x08):
				rsa.init(keypair.getPrivate(), Cipher.MODE_DECRYPT);
				short bytesRead = apdu.setIncomingAndReceive();
				Util.arrayCopyNonAtomic(buf, ISO7816.OFFSET_CDATA, buf, (short)0, bytesRead);
				messageDigest.reset();
				Util.arrayFillNonAtomic(tbuf, (short)0, (short)256, (byte)0x00);
				tbuf[0] = (byte) 0x00;
				tbuf[1] = (byte) 0x01;
				Util.arrayFillNonAtomic(tbuf, (short)2, (short)202, (byte)0xFF);
				tbuf[204] = (byte) 0x00;
				Util.arrayCopyNonAtomic(sha256Prefix, (short)0, tbuf, (short)205, (short) sha256Prefix.length);
				messageDigest.doFinal(dbuf, (short)0, bytesRead, tbuf, (short)224);
				rsa.doFinal(tbuf, (short)0, (short)256, buf, (short)0);
				Util.arrayFillNonAtomic(tbuf, (short)0, (short)256, (byte)0x00);
				Util.arrayFillNonAtomic(dbuf, (short)0, (short)256, (byte)0x00);
				apdu.setOutgoingAndSend((short)0, (short)256);
				return;
		}
		ISOException.throwIt(ISO7816.SW_INS_NOT_SUPPORTED);
	}
}

/*
ant
java -jar gp.jar --deletedeps --delete 0102030405
java -jar gp.jar --install applet.cap --default
python3 test_applet.py
*/