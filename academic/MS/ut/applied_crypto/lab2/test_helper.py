#!/usr/bin/env python3
import sys, os, hashlib, traceback, codecs

### must be executed from the directory where asn1_encoder.py resides

error = {}
grade = False
if len(sys.argv) > 2: grade = True
asn1name = "asn1.der.produced"

try:
    os.remove(asn1name)
except:
    pass


dername = "asn1.der.expected"

# write DER structure that we expect to obtain
der = """
a07230703110020105a204020200c8ab05020300ff7f0101ff030205c00433
00010202020202020202020202020202020202020202020202020202020202
0202020202020202020202020202020202020202050006072a864886f70d01
130668656c6c6f2e170d3135303232333031303930305a
"""
open(dername, 'wb').write(codecs.decode(der.replace("\n",""), 'hex'))
sys.argv = ["", asn1name]
from helper2 import *

# check if output DER created
if not os.path.isfile(asn1name):
    print("[-] No output DER produced!")
    error['output'] = {'success':0, 'error':2}
else:
    # check if matches expected
    digest_produced = codecs.encode(hashlib.sha1(open(asn1name, 'rb').read()).digest(), 'hex')
    digest_expected = codecs.encode(hashlib.sha1(open(dername, 'rb').read()).digest(), 'hex')
    if digest_produced != digest_expected:
        print("[-] Produced DER file does not match expected!")
        os.system("dumpasn1 " + dername + " > der.expect")
        os.system("dumpasn1 " + asn1name + " > der.produced")
        os.system("diff -u der.expect der.produced")
        error['output'] = {'success':1, 'error':1}
    else:
        error['output'] = {'success':2, 'error':0}


def test_der(fname, args, expected):
    global error

    if fname not in error: error[fname] = {'success':0, 'error':0}

    try:
        der = globals()[fname](*args)
        derhex = codecs.encode(der, 'hex')
        if derhex != expected:
            print("[-] %s(%s): Expected '%s' got '%s'" % (fname, repr(args)[:40], expected.decode(), derhex.decode()))
            error[fname]['error'] += 1
        else:
            error[fname]['success'] += 1
        return der
    except:
        print("[-] Failed to execute: %s(%s)" % (fname, repr(args)[:40]))
        print(traceback.format_exc())
        error[fname]['error'] += 1

def print_grade():
    global error
    points = {
	'asn1_len':1.5,
	'asn1_boolean':0,
	'asn1_octetstring':0.2,
	'asn1_null':0.2,
	'asn1_sequence':0.2,
	'asn1_set':0.2,
	'asn1_printablestring':0.2,
	'asn1_utctime':0.2,
	'asn1_tag_explicit':0.3,
	'asn1_integer':1,
	'asn1_objectidentifier':3,
	'asn1_bitstring':2,
	'output':1,
    }

    total = sum([points[test] for test in points])
    print("Total: %sp" % (total))
    obtained = 0
    partial = False
    for test in points:
        if error[test]['error']==0:
            print("[+] PASS %s(): -- %sp" % (test, points[test]))
            obtained+= points[test]
        elif error[test]['success'] > 0:
            print("[?] PARTIAL %s(): -- %s tests out of %s succeeded! (X out of %s points)" % (test, error[test]['success'], error[test]['success']+error[test]['error'], points[test]))
            partial = True
        else:
            print("[-] FAILED %s(): -- 0p out of %sp" % (test, points[test]))
    print("[+] Got %s points! Check PARTIAL and FAILED for manual grading." % (obtained))
test_der("asn1_boolean", [True], b"0101ff")
test_der("asn1_boolean", [False], b"010100")