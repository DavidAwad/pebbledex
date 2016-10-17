# David Awad
#
# export PHONE=10.33.76.245

all:
	pebble build
	ifndef $(PHONE)
		$(error PHONE is not set!!)
	endif
	pebble install --phone $(PHONE)

logs:
	pebble logs --phone $(PHONE)


debug:

screenshot: # make clean f_name
	pebble screenshot --phone $(PHONE) ${f_name}
