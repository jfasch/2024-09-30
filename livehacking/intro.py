tdl = {
    "up 1 to 10": "prefix: 'UP', count up from 1 to 10, interval 1 second",
    "down 1000 to 980": "prefix: 'DOWN', count down from 1000 to 980, interval 0.5 second",
}

for name, desc in tdl.items():
    print(name, desc)
