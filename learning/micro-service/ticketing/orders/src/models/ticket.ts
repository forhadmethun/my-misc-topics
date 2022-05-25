import mongoose from "mongoose";
import {Order, OrderStatus} from "./order";

// An interface that describes the properties
// that are required to create a new Ticket

interface TicketAttrs {
    title: string;
    price: number;
}

// An interface that describes the properties
// that a Ticket Document has
export interface TicketDoc extends mongoose.Document {
    title: string;
    price: number;

    isReserved(): Promise<boolean>;
}

// An interface that describes the properties
// that a Ticket Model has
interface TicketModel extends mongoose.Model<TicketDoc> {
    build(attrs: TicketAttrs): TicketDoc;
}

const ticketSchema = new mongoose.Schema({
    title: {
        type: String,
        require: true
    },
    price: {
        type: Number,
        require: true,
        min: 0
    }
}, {
    toJSON: {
        transform(doc, ret) {
            ret.id = ret._id;
            delete ret._id;
            delete ret.__v;
        }
    }
});

ticketSchema.statics.build = (attrs: TicketAttrs) => {
    return new Ticket(attrs);
};

ticketSchema.methods.isReserved = async function () {
    // this === the ticket document that we just called 'isReserved' on
    const existingOrder = await Order.findOne({
        ticket: this as any,
        status: {
            $in: [
                OrderStatus.Created,
                OrderStatus.AwaitingPayment,
                OrderStatus.Complete,
            ],
        },
    });

    return !!existingOrder;
};

const Ticket = mongoose.model<TicketDoc, TicketModel>('Ticket', ticketSchema);

export {Ticket};
