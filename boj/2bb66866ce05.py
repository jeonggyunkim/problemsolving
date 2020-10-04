data = '''1967 DavidBowie
1969 SpaceOddity
1970 TheManWhoSoldTheWorld
1971 HunkyDory
1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars
1973 AladdinSane
1973 PinUps
1974 DiamondDogs
1975 YoungAmericans
1976 StationToStation
1977 Low
1977 Heroes
1979 Lodger
1980 ScaryMonstersAndSuperCreeps
1983 LetsDance
1984 Tonight
1987 NeverLetMeDown
1993 BlackTieWhiteNoise
1995 1.Outside
1997 Earthling
1999 Hours
2002 Heathen
2003 Reality
2013 TheNextDay
2016 BlackStar'''

data = data.splitlines()
for i in range(len(data)):
    data[i] = data[i].split()
    data[i][0] = int(data[i][0])

tc = int(input())
for i in range(tc):
    a, b = map(int, input().split())
    ans = []
    for j in range(len(data)):
        if data[j][0] >= a and data[j][0] <= b:
            ans.append(j)
    print(len(ans))
    for d in ans:
        print(data[d][0], data[d][1], sep = ' ')