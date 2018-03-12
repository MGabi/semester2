"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   3/1/2018 20:05
"""
class RidePlanification(object):

    def __init__(self, ROWS, COLS, nrVehicles, rides, bonus, steps):
        self.ROWS = ROWS
        self.COLS = COLS
        self.VEH = nrVehicles
        self.RIDES = rides
        self.BONS = bonus
        self.STEPS = steps
        self.CARS = []
        self.FINAL_RIDES = [[] for el in range(self.VEH)]
        #position of every car
        self.CARS = [[0, 0] for el in range(self.VEH)]

    def dist(self, x, y, ex, ey):
        return abs(x-ex) + abs(y-ey)


    def computeRides(self):
        curSteps = 0
        for rideIndex in range(len(self.RIDES)):
            ride = self.RIDES[rideIndex]

            shortest = 0
            car = 0

            for i in range(self.VEH):
                dist = self.dist(self.CARS[i][0], self.CARS[i][1], ride.startX, ride.startY)
                if dist <= shortest:
                    shortest = dist
                    car = i

            dst = self.dist(self.CARS[car][0], self.CARS[car][1], ride.startX, ride.startY)

            if curSteps + dst <= self.STEPS:
                self.CARS[car][0] = ride.endX
                self.CARS[car][1] = ride.endY
                self.FINAL_RIDES[car].append(rideIndex)
                curSteps += dst

        print(curSteps)

            #print("car: ", i, " - ", *self.FINAL_RIDES[i])
        with open("output", "w+") as f:
            line = ""
            for i in range(len(self.FINAL_RIDES)):
                line += str(i) + ""
                for ride in self.FINAL_RIDES[i]:
                    line += " " + str(ride)
                line += "\n"
                f.write(line)
                line = ""
