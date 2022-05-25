import {Ticket} from "../../models/ticket";
import request from "supertest";
import {app} from "../../app";
import {OrderStatus} from "../../models/order";

const buildTicket = async () => {
    const ticket = Ticket.build({
        title: 'concert',
        price: 20
    });
    await ticket.save();
    return ticket;
}

it('marks an order as cancelled', async () => {
    // create a ticket
    const ticket = await buildTicket();

    const user = global.signin();

    // make a request to create an order
    const {body: order} = await request(app)
        .post('/api/orders')
        .set('Cookie', user)
        .send({ticketId: ticket.id})
        .expect(201);

    // make a request to cancel an order
    const {body: cancelledOrder} = await request(app)
        .delete(`/api/orders/${order.id}`)
        .set('Cookie', user)
        .send({ticketId: ticket.id})
        .expect(204);

    // expectation to make sure that the order is cancelled
    expect(order.status).toEqual(OrderStatus.Created);
    expect(cancelledOrder.status).toEqual(OrderStatus.Cancelled);
});

it.todo('emits a order cancelled event');
