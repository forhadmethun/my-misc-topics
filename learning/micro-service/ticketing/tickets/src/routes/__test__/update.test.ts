import request from "supertest";
import {app} from "../../app";
import {Ticket} from "../../models/ticket";
import mongoose from "mongoose";
import {natsWrapper} from "../../nats-wrapper";

it('returns 404 if the provided id does not exist', async () => {
    const id = new mongoose.Types.ObjectId().toHexString();
    const response = await request(app)
        .put(`/api/tickets/${id}`)
        .set('Cookie', global.signin())
        .send({
            title: 'ilaksjdfasd',
            price: 20
        }).expect(404);
});

it('can only be accessed if the user is signed in', async () => {
    const id = new mongoose.Types.ObjectId().toHexString();
    await request(app)
        .put(`/api/tickets/${id}`)
        .send({
            title: 'ilaksjdfasd',
            price: 20
        })
        .expect(401);
})

it('return status 401 if user does not own the ticket', async () => {
    const title = 'some title';
    const response = await request(app)
        .post('/api/tickets')
        .set('Cookie', global.signin())
        .send({title, price: 10})
        .expect(201);

    await request(app)
        .put(`/api/tickets/${response.body.id}`)
        .set('Cookie', global.signin())
        .send({title: 'lajsdfasdf', price: 12})
        .expect(401)
})

it('returns 400 if invalid title or price', async () => {
    const cookie = global.signin();
    const response = await request(app)
        .post('/api/tickets')
        .set('Cookie', cookie)
        .send({title: ';kaljsdf', price: 10})
        .expect(201);

    await request(app)
        .put(`/api/tickets/${response.body.id}`)
        .set('Cookie', cookie)
        .send({title: '', price: 12})
        .expect(400);

    await request(app)
        .put(`/api/tickets/${response.body.id}`)
        .set('Cookie', cookie)
        .send({title: 'asdf', price: -10})
        .expect(400);
});
//
// it('returns an error if invalid price is provided', async () => {
//     await request(app)
//         .post('/api/tickets')
//         .set('Cookie', global.signin())
//         .send({title: 'some title', price: -10})
//         .expect(400);
//
//     await request(app)
//         .post('/api/tickets')
//         .set('Cookie', global.signin())
//         .send({title: 'some title'})
//         .expect(400);
// });
//
it('Update a ticket with valid parameters', async () => {
    const cookie = global.signin();
    const response = await request(app)
        .post('/api/tickets')
        .set('Cookie', cookie)
        .send({title: ';kaljsdf', price: 10})
        .expect(201);

    await request(app)
        .put(`/api/tickets/${response.body.id}`)
        .set('Cookie', cookie)
        .send({title: 'new title', price: 12})
        .expect(200);

    const ticketResponse = await request(app)
        .get(`/api/tickets/${response.body.id}`)
        .send();

    expect(ticketResponse.body.title).toEqual('new title');
    expect(ticketResponse.body.price).toEqual(12);
});

it('publish an event', async () => {
    const cookie = global.signin();
    const response = await request(app)
        .post('/api/tickets')
        .set('Cookie', cookie)
        .send({title: ';kaljsdf', price: 10})
        .expect(201);

    await request(app)
        .put(`/api/tickets/${response.body.id}`)
        .set('Cookie', cookie)
        .send({title: 'new title', price: 12})
        .expect(200);
    expect(natsWrapper.client.publish).toHaveBeenCalled();
});