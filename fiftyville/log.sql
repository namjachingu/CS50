-- Gathering information about the crime.
SELECT * FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28;
-- id: 295|2020|7|28|Chamberlin Street|Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts
-- mentions the courthouse.

-- Information from the witnesses:
SELECT * FROM interviews WHERE month = 7 AND day > 27 AND id > 160;

-- Find flight information:
SELECT * FROM airports WHERE city = "Fiftyville";
-- 8|CSF|Fiftyville Regional Airport|Fiftyville

-- Find id of earliest flight the morning after:
SELECT id, destination_airport_id FROM flights WHERE origin_airport_id = 8 AND day = 29 ORDER BY hour ASC LIMIT 1; 
-- 36|4

-- Find destination: 
SELECT * FROM airports WHERE id = 4;
-- LONDON


-- Check who left the bank within 10 minutes after the roberry:
SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14;

-- Find passport info based on license plates:
SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14)

-- Which passengers where on that flight and had matching license plate from what was seen in the security cam:
SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14))

-- Query person id in order to find accout number: 
SELECT id FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14)))

-- Account number:
SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14))))

-- Person ID: 
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14)))));
-- 686048 and 467400

-- Name with those IDs:
SELECT name, phone_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND DAY = 28 AND hour = 10 AND minute < 24 AND minute > 14))))));
--Danielle|(389) 555-5198|8496433585
-- Ernest|(367) 555-5533|5773159633

SELECT * FROM phone_calls WHERE caller = "(389) 555-5198" OR caller = "(367) 555-5533" AND day = 28 AND duration < 60;
-- 233|(367) 555-5533|(375) 555-8161|2020|7|28|45 == Ernst
-- Ernst called (375) 555-8161, which is:

SELECT name FROM people WHERE phone_number = "(375) 555-8161";
-- Berthold


