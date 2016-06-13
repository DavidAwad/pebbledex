PHONE = 192.168.1.24

all:
	pebble build
	pebble install --phone $(PHONE) &

logs:
	pebble logs --phone $(PHONE)


debug:	

screen: # make clean f_name
	pebble screenshot --phone $(PHONE) ${f_name} 


