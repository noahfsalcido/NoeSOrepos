# Create a reservation system which books airline seats or hotel rooms. It charges various
# rates for particular sections of the plane or hotel. Example, first class is going to
# cost more than coach. Hotel rooms have penthouse suites which cost more. Keep track of
# when rooms will be available and can be scheduled.
import random
from Airline import Airline
from Databases import Cities
from Hotel import Hotel, set_suite

order_list = [0]
order_dictionary = {}


def save_order_detail(order_class, airline_class, hotel_class):
    x = order.order_number
    order_dictionary[x] = [
                           order_class.__str__() + '\n' + airline_class.__str__() + '\n' + hotel_class.__str__()
                           ]


def enter_trip_information(order_class):

    def enter_origin():
        found = False
        while True:
            try:
                str_tmp = str(input('Enter from where are you traveling:\n'))
            except:
                print('Error in input, please, try again.')
                continue
            else:
                for city in Cities.coordinates:
                    if city == str_tmp:
                        order_class.origin = str_tmp.title()
                        found = True
                        break
                if not found:
                    print('Your Origin is not in our list of destinations, try other')
                    continue
                break

    def enter_destination():
        found = False
        while True:
            try:
                str_tmp = str(input('Enter where do you want to travel:\n'))
            except:
                print('Error in input, please, try again.')
                continue
            else:
                if str_tmp == order_class.origin:
                    print('\nNot possible to make a travel to same city of origin')
                    continue
                for city in Cities.coordinates:
                    if str_tmp == city:
                        order_class.destination = str_tmp.title()
                        found = True
                        break
                if not found:
                    print('Your Destination is not in our list of destinations, try other')
                    continue
                break

    def change_request(request_number):
        if request_number == 1:
            pass
        elif request_number == 2:
            enter_origin()
        elif request_number == 3:
            enter_destination()

    while True:
        try:
            tmp = input('Enter your name:\n')
        except:
            print('Error in input, please, try again.')
            continue
        else:
            order_class.client_name = tmp.title()
            print('Hello, {}!'.format(order_class.client_name))
            break
    enter_origin()
    enter_destination()
    change_requested = 0
    while change_requested != 1:
        try:
            print('Verify your request:\nOrigin: {}\nDestination: {}'.format(order_class.origin, order_class.destination))
            change_requested = int(input("It is correct?\nEnter '1' to be agreed \nPress '2' to change Origin\nPress '3' to change Destination\n"))
        except:
            print('Error in input, please, try again.')
            continue
        else:
            change_request(change_requested)
            continue

    # Print information


def deploy_order_information(order_number):
    print('\n'.join(order_dictionary[order_number]))


class Order:

    order_number = None
    destination = None
    origin = None
    client_name = None
    total_price = None

    def define_order_number(self, client_name):
        while True:
            for item in order_list:
                tmp = str(random.randint(100000, 999999))[1:]
                if tmp is item:
                    continue
                else:
                    self.order_number = tmp
                    order_list.append(str(tmp))
                    break
            break
        self.order_number = client_name[0].upper() + self.order_number

    def checkout_price(self, airline_price, hotel_price):
        self.total_price = str('{0:.2f}'.format(float(airline_price) + float(hotel_price)))

    def __str__(self):
        str_return = 'Order {} information:\nClient: {}\nOrigin: {}\nDestination: {}\nPrice: ${} dlls'
        return str_return.format(self.order_number, self.client_name, self.origin, self.destination, self.total_price)




def all_service():
    while True:
        # Setting Flight
        airline_only()
        # Setting Hotel
        hotel_only()
        break


def hotel_only():
    # Setting Hotel
    print('\nEnter the desired Hotel given its option number:')
    hotel.deploy_hotel_options(hotel.hotels)
    hotel.set_hotel(hotel.hotels)
    suite_tmp = set_suite()
    hotel.set_room(suite_tmp)
    hotel.set_price(suite_tmp, hotel.hotel)
    print(hotel)
    input('\nVerify the data and press any key to continue')


def airline_only():
    # Setting Flight
    airline.look_for_availability(order.destination, order.origin)
    while True:
        try:
            seat_class = int(input(
                "\nPlease select seat class\n'0' for Business Class\n'1' for Comfort Class\n'2' for Economic Class\n"))
        except:
            print("Invalid value, try again")
            continue
        else:
            if 0 <= seat_class <= 2:
                break
            else:
                print("Invalid value, try again")
                continue
    airline.set_seat(seat_class)
    airline.set_flight(airline.company)
    airline.set_price(seat_class, order.origin, order.destination, airline.company)
    print(airline)
    input('Verify the data and press any key to continue')


# Class Definition
order = Order()
airline = Airline()
hotel = Hotel()

# Variable declaration
in_progress = True
option = 3

# Program
while True:
    print("Welcome to 'Quarantine' Travel Services\n")
    input('Press any key to continue')
    while True:
        try:
            option = int(input( "\nPlease select the option:\n'0' for All Service (Flight and Hotel)\n'1' for Flight Only\n'2' for Hotel Only\n'3' to Exit\n"))
        except:
            print("Invalid input, try again")
            continue
        else:
            if 0 <= option <= 3:
                if option == 3:
                    in_progress = False
                break
            else:
                print("Invalid value, try again")
                continue
    while in_progress:
        enter_trip_information(order)
        order.define_order_number(order.client_name)
        if option == 0:
            all_service()
        elif option == 1:
            airline_only()
        elif option == 2:
            hotel_only()
        order.checkout_price(airline.price, hotel.price)
        save_order_detail(order, airline, hotel)
        deploy_order_information(order.order_number)
        input('\nVerify the data and press any key to continue')
        break




