a.out : main.o booking.o reserve.o ticket_details.o cancel_ticket.o login.o sign_in_account.o sign_up_account.o train_details.o
	gcc main.o booking.o reserve.o ticket_details.o cancel_ticket.o login.o sign_in_account.o sign_up_account.o train_details.o

main.o : main.c
	gcc -c main.c

booking.o : booking.c
	gcc -c booking.c

reserve.o : reserve.c
	gcc -c reserve.c

ticket_details.o : ticket_details.c
	gcc -c ticket_details.c

cancel_ticket.o : cancel_ticket.c
	gcc -c cancel_ticket.c

login.o : login.c
	gcc -c login.c

sign_in_account.o : sign_in_account.c
	gcc -c sign_in_account.c

sign_up_account.o : sign_up_account.c
	gcc -c sign_up_account.c

train_details.o : train_details.c
	gcc -c train_details.c


