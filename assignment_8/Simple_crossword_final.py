import copy

lenght_word_dictionary = {0:""}

set_of_elements = {'b', 'c', 'r', '.'}

crossword = []


 
n, m = map(int, input().split())

for i in range(n):
    crossword.append(list(input()))
    #crossword.append(list(map(str, input().split())))

answer = copy.deepcopy(crossword)       # this is the deep copy of crossword in which i will fill the answers


number_of_words = int(input())

for i in range(number_of_words):
    word = input()
    lenght_word_dictionary[len(word)] = word

def print_crossword():

    for row_count in range(m):
        for column_count in range(n):
            print(answer[row_count][column_count], end = '')
        print()


def places_vacant_on_the_right(i, j):
    count = 1
    temp = 1
    while j+temp < m:       # total column count is m
        
        if crossword[i][j+temp] == 'b' or crossword[i][j+temp] == 'r':
                count+=1
                return count
        else:
            count+=1

        
        temp+=1
    return 0


def places_vacant_on_the_downside(i, j):
    count = 1
    temp = 1
    while i+temp < n:
        
        if crossword[i+temp][j] == 'b' or crossword[i+temp][j] == 'c':
                count+=1
                return count
        else:
            count+=1

        
        temp+=1
    return 0

for var in range(m*n):

    
    row = var//n
    column = var%n

    if crossword[row][column] == 'c':
        
        length = places_vacant_on_the_downside(row, column)
        #print(length)
        if length in lenght_word_dictionary.keys():
            potential_word = lenght_word_dictionary[length]
        else:                               # if dict does not contain word of required length just print invalid
            print("Invalid")
            exit(0)

        for j in range(len(potential_word)):
            row_index, column_index = row+j, column
            if answer[row_index][column_index] in set_of_elements or answer[row_index][column_index] == potential_word[j]:
                
                answer[row_index][column_index] = potential_word[j]
            
            else:
                print("Invalid")            # if some other letter was already mapped then it's a fail
                exit(0)
            
        
    if crossword[row][column] == 'r':
        length = places_vacant_on_the_right(row, column)

        if length in lenght_word_dictionary.keys():
            potential_word = lenght_word_dictionary[length]
        else:                               # if dict does not contain word of required length just print invalid
            print("Invalid")
            exit(0)

        for j in range(len(potential_word)):
            row_index, column_index = row, column+j
            if answer[row_index][column_index] in set_of_elements or answer[row_index][column_index] == potential_word[j]:
                answer[row_index][column_index] = potential_word[j]
            
            else:
                print("Invalid")            # if some other letter was already mapped then it's a fail
                exit(0)
    
    if crossword[row][column] == 'b':

        length_1 = places_vacant_on_the_right(row, column)
        


        if length_1 in lenght_word_dictionary.keys():
            potential_word = lenght_word_dictionary[length_1]
        else:                               # if dict does not contain word of required length just print invalid
            print("Invalid")
            exit(0)

        for j in range(len(potential_word)):
            row_index, column_index = row, column+j
            if answer[row_index][column_index] in set_of_elements or answer[row_index][column_index] == potential_word[j]:
                answer[row_index][column_index] = potential_word[j]
            
            else:
                print("Invalid")            # if some other letter was already mapped then it's a fail
                exit(0)

        length_2 = places_vacant_on_the_downside(row, column)

        if length_2 in lenght_word_dictionary.keys():
            potential_word = lenght_word_dictionary[length_2]
        else:                               # if dict does not contain word of required length just print invalid
            print("Invalid")
            exit(0)

        for j in range(len(potential_word)):
            row_index, column_index = row+j, column
            if answer[row_index][column_index] in set_of_elements or answer[row_index][column_index] == potential_word[j]:
                
                answer[row_index][column_index] = potential_word[j]
            
            else:
                print("Invalid")            # if some other letter was already mapped then it's a fail
                exit(0)
            

print_crossword()