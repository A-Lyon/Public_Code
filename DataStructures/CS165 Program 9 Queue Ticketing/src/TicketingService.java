import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class TicketingService {

    public static void main (String[] args) {
        Scanner scnr = new Scanner(System.in);
        String personName = "";
        int counter = 0;
        int youPosition = 1;

        Queue<String> peopleInQueue = new LinkedList<String>();

        personName = scnr.nextLine();
        while (!personName.equals("-1")) {
            peopleInQueue.add(personName);
            counter++;
            // TODO: Add personName to peopleInQueue and
            //       determine position of "You" (youPosition)

            personName = scnr.nextLine();
            if(personName.equalsIgnoreCase("you")){
                youPosition = counter + 1;
            }
        }

        System.out.println("Welcome to the ticketing service... ");
        System.out.println("You are number " + youPosition + " in the queue.");

        // TODO: In a loop, remove head person from peopleInQueue,
        //       output their name and that they have purchased a ticket,
        //       then output your position in the queue. When you are at
        //       the head, output that you can purchase your ticket.
        while(youPosition > 1){
            System.out.println(peopleInQueue.poll() + " has purchased a ticket.");
            youPosition--;
            System.out.println("You are now number " + youPosition);
        }
        System.out.println("You can now purchase your ticket!");

        /*
        Welcome to the ticketing service...
        You are number 3 in the queue.
        Zadie Smith has purchased a ticket.
        You are now number 2
        Tom Sawyer has purchased a ticket.
        You are now number 1
        You can now purchase your ticket!
         */

    }
}
