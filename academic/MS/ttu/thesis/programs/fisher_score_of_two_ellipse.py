from numpy import *
from matplotlib.pyplot import *
from math import sqrt
from math import pow
import random

NUM_OF_POINTS = 360

CENTER_X = 0
CENTER_Y = 0

RADIUS_ON_X_AXIS = 80
RADIUS_ON_Y_AXIS = 10

FIRST_ELLIPSE_SHIFT_Y = 0
SECOND_ELLIPSE_SHIFT_Y = 0
SECOND_ELLIPSE_SHIFT_Y_PREV = 50

# x axis value list.
x_number_list = []

# y axis value list.
y_number_list = []



def draw_multiple_points():


    # Draw point based on above x, y axis values.
    scatter(x_number_list, y_number_list, s=20)

    # Set chart title.
    title("Extract Number Root ")

    # Set x, y label text.
    xlabel("Number")
    ylabel("Extract Root of Number")
    # plt.show()

def generate_ellipse(center_x, center_y, radius_x, radius_y, shift_x, shift_y, rotate_degree):
    global NUM_OF_POINTS
    theta = radians(rotate_degree)

    t = linspace(0, NUM_OF_POINTS, NUM_OF_POINTS)
    x = radius_x * cos(radians(t)) + center_x + shift_x
    y = radius_y * sin(radians(t)) + center_y + shift_y

    u = x * cos(theta) - y * sin(theta)
    v = x * sin(theta) + y * cos(theta)
    # u = x
    # v = y

    for i in range(1, 1000):
        sq_radius_x = radius_x * radius_x
        sq_radius_y = radius_y * radius_y

        rx = random.randrange(-100, 100)
        ry = random.randrange(-100, 100)

        h = center_x + shift_x
        k = center_y + shift_y

        x_h = rx - h
        y_h = ry - k
        sq_x_h = x_h * x_h
        sq_y_h = y_h * y_h
        if ((sq_x_h / sq_radius_x) + (sq_y_h / sq_radius_y) <= 1):
            x_number_list.append(rx)
            y_number_list.append(ry)
    plot(u, v)
    return u, v

def draw_ellipse(shift_up):
    global NUM_OF_POINTS, CENTER_X, CENTER_Y, RADIUS_ON_X_AXIS, RADIUS_ON_Y_AXIS
    t = linspace(0, NUM_OF_POINTS, NUM_OF_POINTS)
    x = RADIUS_ON_X_AXIS * cos(radians(t)) + CENTER_X
    y = RADIUS_ON_Y_AXIS * sin(radians(t)) + shift_up + CENTER_Y
    plot(x, y)
    return x, y


"""
F = Ej,k(Pj(uj-u)^2)/Ej,k(Pj * oj^2)
uj = mean of data points belonging to class j 
oj = standard deviation of data points belonging to class j 
pj = fractions of data points belonging to class j
u = global mean of data on the feature being evaluated 
"""


def calculate_fisher(mean_u, j):
    mean_uj = mean(j)
    std_oj = std(j)
    num_j = 0
    denom_j = 0
    for pj in j:
        num_j = num_j + pj * pow((mean_uj - mean_u), 2)
        denom_j = denom_j + pj * pow(std_oj, 2)
    fj = num_j / denom_j
    return fj


def fisher(x_list, y_list):
    mean_u = mean(x_list + y_list)
    return calculate_fisher(mean_u, x_list), calculate_fisher(mean_u, y_list)


"""
    pj = fractions of data points belonging to the class j 
    E(vi) = - Ej,k (Pj*log2(Pj))
"""


def get_number_of_points_in_interval(list, start_interval, end_interval):
    count = 0
    for num in list:
        if num >= start_interval and num <= end_interval:
            count = count + 1
    return count


def calculate_entropy_clustering(list_j, radius, interval_step, interval_m):
    entropy_j = 0
    for i in range(1, interval_m + 1):
        start_interval, end_interval = -radius + interval_step * (i - 1), -radius + interval_step * i
        pj = get_number_of_points_in_interval(list_j, start_interval, end_interval) / len(list_j)
        if pj != 0:
            entropy_j = entropy_j + pj * log2(pj) + (1 - pj) * log2(1 - pj)
    return entropy_j


def entropy_clustering(x_list, y_list, interval_m):
    interval_step = ((2 * RADIUS_ON_X_AXIS) / interval_m)
    entropy_x = calculate_entropy_clustering(x_list, RADIUS_ON_X_AXIS, interval_step, interval_m)
    entropy_y = calculate_entropy_clustering(y_list, RADIUS_ON_Y_AXIS, interval_step, interval_m)
    return -entropy_x, -entropy_y


def calculate_entropy_classification(list_j, radius, interval_step, interval_m):
    entropy_j = 0
    for i in range(1, interval_m + 1):
        start_interval, end_interval = -radius + interval_step * (i - 1), -radius + interval_step * i
        pj = get_number_of_points_in_interval(list_j, start_interval, end_interval) / len(list_j)
        if pj != 0:
            entropy_j = entropy_j + pj * log2(pj)
    return entropy_j


def entropy_classification(x_list, y_list, interval_m):
    interval_step = ((2 * RADIUS_ON_X_AXIS) / interval_m)
    entropy_x = calculate_entropy_classification(x_list, RADIUS_ON_X_AXIS, interval_step, interval_m)
    entropy_y = calculate_entropy_classification(y_list, RADIUS_ON_Y_AXIS, interval_step, interval_m)
    return -entropy_x, -entropy_y


"""
a1, a2... ar -> distance of data points R sub D
b1, b2... br -> distance of data point S
H = (Ei,r bi)/(E i,r (ai + bi)
"""

"""
a1, a2... ar -> distance of data points R sub D
b1, b2... br -> distance of data point S
H = (Ei,r bi)/(E i,r (ai + bi)
"""


def dist(x1, x2, y1, y2):
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))


def distance_list(listx, listy):
    d = []
    for i in range(1, len(listx)):
        d.append(dist(listx[i], listx[i - 1], listy[i], listy[i - 1]))
    return d


def hopkins_statistics(ellipse1, ellipse2):
    a_list = distance_list(ellipse1[0] + ellipse2[0], ellipse1[1] + ellipse2[1])
    b_list = distance_list(ellipse1[0], ellipse1[1])  # as Synthetic sample S i took the first ellipse
    sum_a = 0
    sum_b = 0
    for d in a_list:
        sum_a = sum_a + d
    for d in b_list:
        sum_b = sum_b + d
    return sum_b / (sum_a + sum_b)


if __name__ == '__main__':
    # draw ellipse
    # ellipse1, ellipse2 = draw_ellipse(0), draw_ellipse(50)
    # ellipse1 = generate_ellipse(0, 0, 80, 10, -80, 0, -34)
    # ellipse2 = generate_ellipse(0, 0, 80, 10, -80, 0, -135)

    ellipse1 = generate_ellipse(0, 0, 80, 10, -80, 0, 0)
    ellipse2 = generate_ellipse(0, 0, 80, 10, -80, 80, 0)


    draw_multiple_points()
    show()

    # Fisher score
    fx, fy = fisher(ellipse1[0] + ellipse2[0], ellipse1[1] + ellipse2[1])
    print("Fisher score towards X axis, fx: ", fx)
    print("Fisher score towards Y axis, fy: ", fy)
    while True:
        interval_m = int(input("Enter number of intervals: "))

        # Entropy for the feature selection in classification.
        e_class_x, e_class_y = entropy_classification(ellipse1[0] + ellipse2[0], ellipse1[1] + ellipse2[1], interval_m)
        print("Entropy in classification towards X axis, Ex: ", e_class_x)
        print("Entropy in classification towards Y axis, Ey: ", e_class_y)

        # Entropy for the feature selection in clustering.
        e_clust_x, e_clust_y = entropy_clustering(ellipse1[0] + ellipse2[0], ellipse1[1] + ellipse2[1], interval_m)
        print("Entropy in Clustering towards X axis, Ex: ", e_clust_x)
        print("Entropy in Clustering towards Y axis, Ex: ", e_clust_y)

        # Hopkins statistics for the feature selection in clustering.
        H = hopkins_statistics(ellipse1, ellipse2)
        print("Hopkins statistics: ", H)
