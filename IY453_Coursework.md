# IY4113 Milestone 1

| Assessment Details | Please Complete All Details                         |
| ------------------ | --------------------------------------------------- |
| Group              | A                                                   |
| Module Title       | IY453 Software Design and Implementation            |
| Assessment Type    | IY453 Software Design and Implementation Coursework |
| Module Tutor Name  | Jonathon Shore                                      |
| Student ID Number  | P466146                                             |
| Date of Submission |                                                     |
| Word Count         |                                                     |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

---

### Purpose of the Program

---

The purpose of the program is to be designed for easy creation of ticket bookings by staff which can be used at the point of sale as well as making bookings of films for customers and managers can use to plan film showings one week in advance, the program will help in selecting a film, choosing a date and time, entering the required tickets, processing a payment (cash or card), as well as ensuring compliance with the rules of the cinema.

### **Core program functionality**

- **Create bookings**
  
  - Allow selecting a title from the list of movies offered and specifying the time when it is to be shown during the current week (Thursday to Wednesday).
  
  - Collecting customer details and the number of booked tickets for adults, children, students, and senior citizens.
  
  - Ensuring that the selected movie is to be shown according to its schedule and no more tickets can be sold than the seats available.
  
  - Computing the total booking cost using the set ticket prices.Collecting information about the chosen payment means and details of the payment process.
  
  - Capture the payment method (cash or card) and any required payment details.
  
  - Store the completed bookings in memory and save it to a bookings file so it can be viewed and searched later.
  
  **Manage movies**
  
  - Allow staff to add movie details such as title, description, genre, running time, main star, distributor, and release date.
  
  - Store movie details for later use in schedule creation and bookings.
  
  - Display the list of available movies so staff and managers can see which films can be scheduled and booked.
  
  **Manage screens**
  
  - Allow staff to enter details for each screen, including screen ID, maximum seating capacity, and facilities (Standard, IMAX, Couple seats, Seat service, etc.).
  
  - Store screen details so capacity checks and schedule creation can use this information to obey cinema rules.
  
  **Create weekly schedule**
  
  - Allow a manager to select the week to be scheduled (Thursday to Wednesday).
  
  - For each screen, allow the manager to select which film will be shown for that week.
  
  - Allow the manager to enter the start time of the first showing for each day, ensuring it does not start before 10:15.
  
  - For each showing, calculate the end time using the film’s running time and ensure the show does not end after the cinema closing time of 23:30.
  
  - Automatically enforce a 25‑minute gap between consecutive showings on the same screen for cleaning.
  
  - Store all schedule entries in memory and save them to a schedule file in text or CSV format.
  
  **View and search bookings**
  
  - Give an option for staff to view all stored bookings, showing customer name, film, date, time, ticket breakdown, and total cost.
  
  - Allow staff to search bookings by customer name, film title, or date, and show only the matching records.
  
  - Display clear confirmation messages when bookings are created successfully and informative error messages when input is invalid or a booking would overbook a screen.
  
  ---
  
  **System constraints (limitations / rules)**
  
  **Time and opening hours**
  
  - The cinema is open from 10:00 until 23:30 each day.
  
  - The earliest a film can be shown is 10:15, and no show may end after 23:30.
  
  - There must be a 25‑minute gap between the end of one showing and the start of the next showing in the same screen to allow for cleaning.
  
  **Weekly scope**
  
  - The system creates and manages schedules for one week at a time, from Thursday to Wednesday.
  
  - Staff can only make bookings for showings within the current Thursday–Wednesday week.
  
  **Capacity and tickets**
  
  - Each screen has a fixed maximum seating capacity that must not be exceeded when creating a booking.
  
  - Any booking that would exceed the screen’s capacity must be rejected.
  
  - Tickets are sold in four types only: adult, child, student, and senior citizen, each with a fixed ticket price.
  
  **Data storage and interface**
  
  - The program is a text‑based console application that uses menus and keyboard input.
  
  - Bookings and schedule data are stored in text or CSV files so that information is preserved between runs of the program.
  
  - Movie and screen information may initially be stored in memory, with file storage added as needed.
  
  **Scope exclusions**
  
  - The system does not manage staff accounts, user logins, or passwords.
  
  - It does not handle food, drink, or multiple cinema locations.
  
  - Card details are collected to process a transaction but are not stored permanently in any database.

---

### Input Process Output Table

---



---

### Algorithms

---

---


