greet = input("Greeting: ")

money = 0

if 'Hello' in greet:
    print("$0")

if 'H' in greet[0] and 'Hello' not in greet:
    print("$20")

else:
    print("$100")

