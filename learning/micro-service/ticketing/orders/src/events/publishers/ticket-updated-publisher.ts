import {Publisher, Subjects, TicketUpdatedEvent} from "@fmticketing/common";

export class TicketUpdatedPublisher extends Publisher<TicketUpdatedEvent> {
    subject: TicketUpdatedEvent["subject"] = Subjects.TicketUpdated;
}