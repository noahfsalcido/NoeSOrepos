# Destinations
#   Europe 10.5 HR
from math import sqrt
coordinates = {
               # Europe
               'London': [51.5, 0.051],
               'Madrid': [40.49, -3.5],
               'Paris': [49, 2.54],
               'Lisboa': [38.77, -9.13],
               'Roma': [41.79, 12.25],
               'Berlin': [52.36, 13.50],
               'Amsterdam': [52.31, 4.77],
               'Helsinki': [60.31, 24.95],
               'Stockholm': [59.35, 17.94],
               'Oslo': [60.19, 11.09],
               'Athens': [37.93, 23.94],
               'Bucarest': [44.50, 26.08],
               'Kyiv': [50.41, 30.44],
               'Dublin': [53.42, -6.24],
               #   LAmerica
               'Mexico City': [19.43, -99.1],
               'Costa Rica': [9.99, -84.20],
               'Panama': [8.91, -79.59],
               'Bogota': [4.69, -74.11],
               'Caracas': [10.60, -67.00],
               'Peru': [-12.02, -77.10],
               'Habana': [22.99, -82.40],
               #   Middle East
               'Ankara': [40.11, 32.99],
               #   Oriental Asia
               'Pekin': [40.07, 116.60],
               'Seoul': [37.44, 126.45],
               'Tokyo': [35.54, 139.78],
               #   Russia
               'Moscow': [55.60, 37.28],
               #   NAmerica
               'Los Angeles': [33.94, -118.41],
               'Chicago': [41.78, -87.75],
               'New York': [40.64, -73.78],
               'Washington': [38.85, -77.04],
               'Montreal': [45.46, -73.74],
               'Vancouver': [49.19, -123.17],
               'Ottawa': [45.32, -75.66],
               'Anchorage': [61.17, -149.98],
               'Miami': [25.79, -80.27],
               #   SAmerica
               'Rio De Janeiro': [-22.80, -43.25],
               'Buenos Aires': [-34.55, -58.41],
               'Santiago': [-33.39, -70.8],
               #   NAfrica
               #   SAfrica
               #   Oceania
               }


def calculate_distance(origin, destination):
    origin_coordinates = coordinates[origin]
    destination_coordinates = coordinates[destination]
    a = (destination_coordinates[0] - origin_coordinates[0]) ** 2
    b = (destination_coordinates[1] - origin_coordinates[1]) ** 2
    return sqrt(a + b)