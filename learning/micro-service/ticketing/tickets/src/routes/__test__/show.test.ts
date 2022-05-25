import request from "supertest";
import {app} from "../../app";
import mongoose from "mongoose";

it('returns 404 if the ticket is not found', async () => {
    const id = new mongoose.Types.ObjectId().toHexString();
    const response = await request(app)
        .get(`/api/tickets/${id}`)
        .send();
    expect(response.status).toEqual(404);
});

it('returns the ticket if the ticket is found', async () => {
    let [price, title] = [20, 'some ticket']
    const response = await request(app)
        .post('/api/tickets')
        .set('Cookie', global.signin())
        .send({
            title,
            price
        })
        .expect(201);

    const ticketResponse = await request(app)
        .get(`/api/tickets/${response.body.id}`)
        .send()
        .expect(200);
    expect(ticketResponse.body.title).toEqual(title);
    expect(ticketResponse.body.price).toEqual(price);
});

