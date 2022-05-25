import request from 'supertest';
import { app } from '../../app';

it('fails when an email that does not exist is supplied', async () => {
    return request(app)
        .post('/api/users/signin')
        .send({
            email: 'test@test.com',
            password: 'pass'
        })
        .expect(400);
});

it('fails when an incorrect password is supplied', async () => {
    await request(app)
        .post('/api/users/signup')
        .send({
            email: 'test@test.com',
            password: 'pass'
        })
        .expect(201);

    await request(app)
        .post('/api/users/signin')
        .send({
            email: 'test@test.com',
            password: 'invalidpass'
        })
        .expect(400);
});

it('response with a cookie when given valid credential', async () => {
    await request(app)
        .post('/api/users/signup')
        .send({
            email: 'test@test.com',
            password: 'pass'
        })
        .expect(201);

    const response = await request(app)
        .post('/api/users/signin')
        .send({
            email: 'test@test.com',
            password: 'pass'
        })
        .expect(200);

    expect(response.get('Set-Cookie')).toBeDefined();
});