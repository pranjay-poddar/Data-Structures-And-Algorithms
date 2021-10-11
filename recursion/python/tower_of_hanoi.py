def TowerOfHanoi(number_of_plates , from_rod, to_rod, aux_rod):
    if number_of_plates == 1:
        print("Move disk 1 from rod",from_rod,"to rod",to_rod)
        return
    TowerOfHanoi(number_of_plates-1, from_rod, aux_rod, to_rod)
    print("Move disk",number_of_plates,"from rod",from_rod,"to rod",to_rod)
    TowerOfHanoi(number_of_plates-1, aux_rod, to_rod, from_rod)

# Driver code
n = 4
TowerOfHanoi(n, 'A', 'C', 'B') 
# A, C, B are the name of rods
