-- Keep a log of any SQL queries you execute as you solve the mystery.

-- All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.

-- Find crime scene report
SELECT description FROM crime_scene_reports WHERE street = 'Chamberlin Street' AND month = 7 AND day = 28;

--Response:
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.


-- Find interviews
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE "%courthouse%";

--Response:
-- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Look at ATM Records

-- Response:
SELECT amount, account_number from atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"
48 | 28500762
20 | 28296815
60 | 76054385
50 | 49610011
80 | 16153065
20 | 25506511
30 | 81061156
35 | 26013199

-- Look at account holders
-- Response:
SELECT name, account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN
(SELECT account_number from atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw");

Ernest | 49610011
Russell | 26013199
Roy | 16153065
Bobby | 28296815
Elizabeth | 25506511
Danielle | 28500762
Madison | 76054385
Victoria | 81061156

-- Find thief's car
SELECT name, phone_number, passport_number FROM people where license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit" AND minute BETWEEN 5 AND 25)
ORDER BY name;

--Response:
Danielle | (389) 555-5198 | 8496433585
Elizabeth | (829) 555-5269 | 7049073643
Ernest | (367) 555-5533 | 5773159633
Evelyn | (499) 555-9472 | 8294398571
Patrick | (725) 555-4692 | 2963008352
Roger | (130) 555-0289 | 1695452385
Russell | (770) 555-1861 | 3592750733

-- Find Intersection of car and accounts
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN
(SELECT account_number from atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw")
INTERSECT
SELECT name FROM people where license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit" AND minute BETWEEN 5 AND 25);

-- Response:
Danielle
Elizabeth
Ernest
Russell

-- Find flight out of Fiftyville on 7/29
SELECT flights.id from flights
JOIN airports ON flights.origin_airport_id = airports.id
JOIN passengers ON flights.id = passengers.flight_id
WHERE airports.city = "Fiftyville"
AND month = 7 AND day = 29
AND passport_number IN ("Insert Passport Number");

Danielle 8496433585 - FL 36
Elizabeth 7049073643 - Not found
Ernest 5773159633 - FL 36
Russell 3592750733 - FL 18

-- Determine earliest flight
SELECT id, hour, minute, destination_airport_id FROM flights WHERE id IN ("18", "36");
-- Response:
18 | 16 | 0 | 6
36 | 8 | 20 | 4

-- Destination airport
SELECT full_name FROM airports WHERE id = 4;
-- Response:
Heathrow Airport

-- Find call logs
-- Danielle
SELECT receiver, duration FROM phone_calls WHERE  month = 7 AND day = 28 AND caller = "(389) 555-5198";

-- Ernest
SELECT name, phone_number, duration FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE month = 7 AND day = 28 AND caller = "(367) 555-5533";
Berthold | (375) 555-8161 | 45
Deborah | (344) 555-9601 | 120
Gregory | (022) 555-4052 | 241
Carl | (704) 555-5790 | 75

-- Russell
SELECT name, phone_number, duration FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE month = 7 AND day = 28 AND caller = "(770) 555-1861";
Philip | (725) 555-3243 | 49

