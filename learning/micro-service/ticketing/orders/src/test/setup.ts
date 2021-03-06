import {MongoMemoryServer} from 'mongodb-memory-server';
import mongoose, {ConnectOptions} from 'mongoose';
import request from 'supertest';
import {app} from '../app';
import jwt from 'jsonwebtoken';

declare global {
    var signin: () => string[];
}

jest.mock('../nats-wrapper');

let mongo: any;
beforeAll(async () => {
    process.env.JWT_KEY = 'asdf';
    mongo = new MongoMemoryServer();
    await mongo.start();
    const mongoUri = await mongo.getUri();

    await mongoose.connect(mongoUri, {
        useNewUrlParser: true,
        useUnifiedTopology: true
    } as ConnectOptions);
});

beforeEach(async () => {
    jest.clearAllMocks();
    const collections = await mongoose.connection.db.collections();
    for (let collection of collections) {
        await collection.deleteMany({});
    }
});

afterAll(async () => {
    await mongo.stop();
    await mongoose.connection.close();
});

global.signin = () => {
    // build a JWT payload. {id, email}
    const payload = {
        id: new mongoose.Types.ObjectId().toHexString(),
        email: 'test@test.com'
    }

    // Create the JWT!
    const token = jwt.sign(payload, process.env.JWT_KEY!)

    // build the session Object, {jwt: MY_JWT}
    const session = {jwt: token};

    // Turn that session into json
    const sessionJSON = JSON.stringify(session);

    // Take json and encode it as base 64
    const base64 = Buffer.from(sessionJSON).toString('base64');

    // return a string that the cookie with the encoded data
    return [`session=${base64}`];
}

