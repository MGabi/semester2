"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   3/1/2018 19:55
"""
class RidePlanification(object):

    def __init__(self, ROWS, COLS, nrVehicles, rides, bonus, steps, fileName):
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
        self.FILE = fileName

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
        with open(self.FILE+".out", "w+") as f:
            line = ""
            for i in range(len(self.FINAL_RIDES)):
                line += str(len(self.FINAL_RIDES[i])) + ""
                for ride in self.FINAL_RIDES[i]:
                    line += " " + str(ride)
                line += "\n"
                f.write(line)
                line = ""

class Car(object):

    def __init__(self, posX, posY):
        self.posX = posX
        self.posY = posY

class Ride(object):

    def __init__(self, startX, startY, endX, endY, startT, endT):
        self.startX = startX
        self.startY = startY
        self.endX = endX
        self.endY = endY
        self.startT = startT
        self.endT = endT

def main():
    ROWS = 0
    COL = 0
    VEH = 0
    RIDES_NR = 0
    BONUS = 0
    STEPS = 0
    RIDES = []
    files = ["a_example", "b_should_be_easy", "c_no_hurry", "d_metropolis", "e_high_bonus"]
    # for i in range(len(fi:les)):
    for i in range(3)
        with open(files[i]+".in", "r") as f:
            try:
                line = [int(el) for el in f.readline().split()]
                ROWS = line[0]
                COL = line[1]
                VEH = line[2]
                RIDES_NR = line[3]
                BONUS = line[4]
                STEPS = line[5]

                line = [int(el) for el in f.readline().split()]

                while line != []:
                    ride = Ride(line[0], line[1], line[2], line[3], line[4], line[5])
                    RIDES.append(ride)
                    line = [int(el) for el in f.readline().split()]

            except EOFError as eof:
                f.close()
                pass
            finally:
                rp = RidePlanification(ROWS, COL, VEH, RIDES, BONUS, STEPS, files[i])
                rp.computeRides()
main()