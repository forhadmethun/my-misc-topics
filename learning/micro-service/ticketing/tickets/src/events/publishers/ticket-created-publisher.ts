import {Publisher, Subjects, TicketCreatedEvent} from "@fmticketing/common";

export class TicketCreatedPublisher extends Publisher<TicketCreatedEvent> {
    subject: TicketCreatedEvent["subject"] = Subjects.TicketCreated;
}