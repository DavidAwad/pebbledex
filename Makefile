PHONE = 172.31.52.37

all:
	pebble build
	pebble install --phone $(PHONE) &

logs:
	pebble logs --phone $(PHONE)






