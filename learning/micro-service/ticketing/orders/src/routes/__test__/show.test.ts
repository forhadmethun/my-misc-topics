import request from 'supertest';
import {app} from '../../app';
import {Ticket} from "../../models/ticket";

const buildTicket = async () => {
    const ticket = Ticket.build({
        title: 'concert',
        price: 20
    });
    await ticket.save();
    return ticket;
}

it('fetch the order', async () => {
    // create three ticket
    const ticket = await buildTicket();

    const user = global.signin();

    // Create one order
    const {body: order} = await request(app)
        .post('/api/orders')
        .set('Cookie', user)
        .send({ticketId: ticket.id})
        .expect(201);

    // Make request to get orders for user #2
    const {body: fetchedOrder} = await request(app)
        .get(`/api/orders/${order.id}`)
        .set('Cookie', user)
        .expect(200);

    expect(fetchedOrder.id).toEqual(order.id);
});

it('returns an error if one user tries to fetch order of another user', async () => {
    // create three ticket
    const ticket = await buildTicket();

    const user = global.signin();

    // Create one order
    const {body: order} = await request(app)
        .post('/api/orders')
        .set('Cookie', user)
        .send({ticketId: ticket.id})
        .expect(201);

    // Make request to get orders for user #2
    const {body: fetchedOrder} = await request(app)
        .get(`/api/orders/${order.id}`)
        .set('Cookie', global.signin())
        .expect(401);
});