import random

words = ["python", "foo", "poo", "pee", "supr"]

word = random.choice(words)

incorrect_guesses = 0
correct_guesses = 0
used_letters = []

display = ["_"] * len(word)

while incorrect_guesses < 6 and "_" in display:
    guess = input("Guess a letter: ").lower()

    if guess in used_letters:
        print("You already used that letter. Try again.")
    elif guess in word:
        print("Correct!")
        used_letters.append(guess)
        correct_guesses += 1
        
        for i in range(len(word)):
            if word[i] == guess:
                display[i] = guess
        print(" ".join(display))
    else:
        print("Incorrect!")
        incorrect_guesses += 1


if "_" not in display:
    print("Congratulations! You won!")
else:
    print("Sorry, you lost. The word was " + word + ".")
