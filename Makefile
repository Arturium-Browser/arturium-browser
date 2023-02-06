.DEFAULT_GOAL := all

FNAME=Arturium_Browser
NAME=arturium-browser
MK = mkdir -p
RM = rm -f

all: $(FNAME)
$(FNAME):
	$(MK) ./$(FNAME)/resources
	cp $(NAME)/* $(FNAME)
	cp build_info.json $(FNAME)/resources
	cp $(NAME)/plugin.py $(FNAME)/resources
	$(CC) -pie -fPIC $(NAME)/$(NAME).c -o $(FNAME)/$(FNAME) -lc
	$(CC) -shared -fPIC $(NAME)/chromedriver.c -o $(FNAME)/chromedriver -lc
	strip $(FNAME)/$(FNAME)
	$(RM) $(FNAME)/$(NAME).c $(FNAME)/plugin.py

install:
	$(MK) /opt/$(NAME)/resources
	cp -r $(FNAME)/* /opt/$(NAME)
	cp $(FNAME)/$(NAME).desktop /usr/share/applications
	cp $(FNAME)/$(NAME).png /usr/share/icons/hicolor/256x256/apps
	ln -s /opt/$(NAME)/$(FNAME) /usr/bin/$(NAME)

clean:
	$(RM) $(FNAME)

remove:
	$(RM) /opt/$(NAME)
	$(RM) /usr/share/applications/$(NAME).desktop
	$(RM) /usr/share/icons/hicolor/256x256/apps/$(NAME).png
	$(RM) /usr/bin/$(NAME)
