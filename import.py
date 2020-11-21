from cs50 import SQL
import cs50
from csv import reader
from sys import argv

db = cs50.SQL("sqlite:///students.db")

if len(argv) != 2:
    print("Usage: python import.py [NAME OF CSV FILE]")
    exit()

with open(argv[1], newline='') as charactersFile:
    characters = reader(charactersFile)
    
    for character in characters:
        if character[0] == 'name':
            continue

        fullName = character[0].split()
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], character[1], character[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], character[1], character[2])
