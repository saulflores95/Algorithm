#We need to find out with what value does insertion beat merge
import math
n = 100
lg = math.log

def insertionVsMerge():
    for i in range(n):
        i += 1
        #print("n:", i, "8log(n):", 8*lg(i, 2)) #We are able to view the value n and the evaluation of 8lg(n)
        if(i <= 8*lg(i, 2)):
            print("n:", i, "insertion is faster")
        else:
            print("n:", i, "merge is faster")

def compareRuningTimes():
    print('Compare running times...')
    runningTimes = []
    oneSec = pow(10, 6)
    oneMin = oneSec * 60
    oneHour = oneMin * 60
    oneDay = oneHour * 24
    oneMonth = oneDay * 31
    oneYear = oneMonth * 12
    oneCentuary = oneYear * 100
    runningTimes = [oneSec, oneMin, oneHour, oneDay, oneMonth, oneYear, oneCentuary]
    for i in range(len(runningTimes)):
        print(
#compareRuningTimes()
print(math.sqrt(3.21408))
