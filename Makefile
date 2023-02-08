.DEFAULT_GOAL := all

FNAME=Arturium_Browser
NAME=arturium-browser
CC_FLAGS = -fPIC -lc
CHROME=chromedriver
MK = mkdir -p
RM = rm -rf
CP = cp -r

all:
	$(MK) $(FNAME)/resources
	$(CP) $(NAME)/* $(FNAME)
	$(CP) $(NAME)/build_info.json $(FNAME)/resources
	$(CP) $(NAME)/plugin.py $(FNAME)/resources
	$(CC) -pie $(CC_FLAGS) $(NAME)/$(NAME).c -o $(FNAME)/$(FNAME) -lpthread
	$(CC) -shared $(CC_FLAGS) -pipe $(NAME)/$(CHROME).c -o $(FNAME)/$(CHROME)
	strip $(FNAME)/$(FNAME)
	strip $(FNAME)/$(CHROME)
	$(RM) $(FNAME)/*.c $(FNAME)/plugin.py

install:
	$(MK) /opt/$(NAME)/resources
	$(CP) $(FNAME)/* /opt/$(NAME)
	$(CP) $(FNAME)/$(NAME).desktop /usr/share/applications
	$(CP) $(FNAME)/$(NAME).png /usr/share/icons/hicolor/256x256/apps
	ln -s /opt/$(NAME)/$(FNAME) /usr/bin/$(NAME)

clean:
	$(RM) $(FNAME)

remove:
	$(RM) /opt/$(NAME)
	$(RM) /usr/share/applications/$(NAME).desktop
	$(RM) /usr/share/icons/hicolor/256x256/apps/$(NAME).png
	$(RM) /usr/bin/$(NAME)
