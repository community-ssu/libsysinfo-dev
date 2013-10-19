all:

clean:

install:
	install -d "$(DESTDIR)/usr/include/"
	install -d "$(DESTDIR)/usr/lib/pkgconfig/"
	install -m 644 sysinfo.h "$(DESTDIR)/usr/include/"
	install -m 644 sysinfo_dbus_names.h "$(DESTDIR)/usr/include/"
	install -m 644 sysinfo.pc "$(DESTDIR)/usr/lib/pkgconfig/"
	ln -s libsysinfo.so.0 "$(DESTDIR)/usr/lib/libsysinfo.so"
