import json

from numpy import number

routers = {
    0 : [
        [],
        []
    ],
    1 :  [
        [],
        []
    ],
    2 :  [
        [],
        []
    ],
    3: [
        [],
        []
    ],
    4: [
        [],
        []
    ],
    5: [
        [],
        []
    ],
    6: [
        [],
        []
    ],
    7: [
        [],
        []
    ],
    8:  [
        [],
        []
    ],
    9: [
        [],
        []
    ]
}



def main():
    f = open("input.json")
    data = json.load(f)
    number_of_routers = data["Number of Routers"]
    print(number_of_routers)

    
main()