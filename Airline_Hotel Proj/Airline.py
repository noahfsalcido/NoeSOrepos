import random
import time
from Databases.Cities import calculate_distance

# Classes
BUSINESS = 0
COMFORT = 1
ECONOMY = 2
# seat rows
BUSINESS_ROWS = 'ADGK'
COMFORT_ROWS = 'ACDEFGHK'
ECONOMY_ROWS = 'ABCDEGHJK'


class Airline:

    airlines = {'Aeromexico': 21, 'American Airlines': 23, 'Iberia': 24,
                'Delta Airlines': 26}
    not_filled = []
    company = ''
    seat = ''  # '17B'
    flight = ''  # '3145'
    departure = ''  # '7:15'
    price = 0  # '6545'

    def set_company(self, company):
        self.company = company

    def set_seat(self, classes):
        high_limit = 40
        low_limit = 11
        row_high = 8
        class_row = ECONOMY_ROWS
        if classes is BUSINESS:
            class_row = BUSINESS_ROWS
            high_limit = 7
            low_limit = 1
            row_high = 3
        elif classes is COMFORT:
            class_row = COMFORT_ROWS
            high_limit = 10
            low_limit = 8
            row_high = 7
        seat = str(random.randint(low_limit, high_limit)) + class_row[random.randint(0, row_high)]
        self.seat = seat

    def set_departure(self, departure):
        self.departure = departure

    def set_flight(self, company):
        self.flight = company[0:2].upper() + str(random.randint(1000, 9999))

    def set_price(self, classes, origin, destination, company):
        price = self.airlines[company] * calculate_distance(origin, destination)
        if classes is BUSINESS:
            price = price * 1.1
        elif classes is COMFORT:
            price = price * 1.05
        self.price = '{0:.2f}'.format(round(price))

    def look_for_availability(self, destination, origin):
        company = ''
        while True:
            rndm = random.randint(0, 3)
            iteration = 0
            for brand in self.airlines:
                if iteration == rndm:
                    company = brand
                    break
                iteration += 1
            hour = str(random.randint(100, 124))[1:3] + ':' + str(random.randint(100, 159))[1:3]
            print(company + '\nfrom ' + origin + ' to ' + destination + '\ndeparture at: ' + hour)
            try:
                accept = int(input("Enter '1' to accept flight or '2' to find other\n"))
            except:
                print("Invalid value, try again")
            else:
                if accept is 1:
                    print('\nFlight accepted')
                else:
                    print('\nSearching . . .')
                    continue
            self.set_company(company)
            self.set_departure(hour)
            break
        return company + '\nfrom ' + origin + ' to ' + destination + '\ndeparture at: ' + hour


    def __str__(self):
        return 'Flight Information:\n  Company: {}\n  Departure: {}\n  Flight: {}\n  Seat: {}\n  Price: ${} dlls'.format(
            self.company, self.departure, self.flight, self.seat, self.price)
