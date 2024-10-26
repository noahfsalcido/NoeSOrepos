import random

# Suites
SINGLE = 0
DOUBLE = 1
MARRIAGE = 2
JR_SUITE = 3
DOUBLE_SUITE = 4
PRESIDENTIAL_SUITE = 5


def set_suite():
    seat_class = None
    while True:
        try:
            seat_class = int(input("\nPlease select class of Room\n'0' for Single Room\n'1' for Double Room \n"
                                   "'2' for Marriage Room \n'3' for Junior Suite\n'4' for Double Suite\n"
                                   "'5' for Presidential Suite"))
        except:
            print("Invalid value, try again")
            continue
        else:
            if 0 <= seat_class <= 5:
                break
            else:
                print("Invalid value, try again")
                continue
    return seat_class


class Hotel:

    hotels = {'Holiday Inn': 155, 'Quality Inn': 65, 'Hilton Garden Inn': 100}

    hotel = ''
    room = ''
    suite = ''
    price = 0

    def deploy_hotel_options(self, hotels):
        option = 1
        for brand in hotels:
            print('Option {} .- Hotel: {} from ${} dollars'.format(option, brand, hotels[brand]))
            option += 1

    def set_hotel(self, hotels):
        while True:
            try:
                desired_hotel = int(input("\nSelect the number of the option of the desired hotel.\n"))
            except:
                print('Error in input, please, try again.')
                continue
            else:
                desired_hotel -= 1
                if desired_hotel >= len(hotels):
                    print('Option {} not available, please, try again'.format(desired_hotel + 1))
                    continue
                iteration = 0
                for brand in hotels:
                    if iteration == desired_hotel:
                        self.hotel = brand
                        break
                    iteration += 1
                break

    def set_room(self, suites):
        high_limit = 115
        low_limit = 101
        if suites is DOUBLE:
            high_limit = 125
            low_limit = 116
            self.suite = 'Double'
        elif suites is MARRIAGE:
            high_limit = 142
            low_limit = 126
            self.suite = 'Marriage'
        elif suites is JR_SUITE:
            high_limit = 209
            low_limit = 201
            self.suite = 'Junior Suite'
        elif suites is DOUBLE_SUITE:
            high_limit = 216
            low_limit = 210
            self.suite = 'Double Suite'
        elif suites is PRESIDENTIAL_SUITE:
            high_limit = 308
            low_limit = 301
            self.suite = 'Presidential Suite'
        else:
            self.suite = 'Single'
        self.room = str(random.randint(low_limit, high_limit))

    def set_price(self, suite, hotel):
        price = self.hotels[hotel]
        if suite is SINGLE:
            price = price * 1.1
        elif suite is MARRIAGE:
            price = price * 1.2
        elif suite is JR_SUITE:
            price = price * 1.3
        elif suite is DOUBLE_SUITE:
            price = price * 1.4
        elif suite is PRESIDENTIAL_SUITE:
            price = price * 1.5
        self.price = '{0:.2f}'.format(round(price))

    def __str__(self):
        return 'Hotel Information:\n  Company: {}\n  Room: {}\n  Suite Class: {}\n  Price: ${} dlls'.format(
            self.hotel, self.room, self.suite, self.price)


#hotel = Hotel()
#suites = 3
#hotel.set_hotel(hotel.hotels)
##hotel.set_room(suites)
#hotel.set_price(suites, hotel.hotel)
#print(hotel)
