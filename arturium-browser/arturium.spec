Name: Arturium_Browser
Version: 286
Release: 7
Summary: Simple browser on PyQt5 and Bash
Group: Applications/Internet
License: MPL v2.0
Source0: %{name}-%{version}.%{release}.tar.gz
BuildArch: x86_64
BuildRoot: %{_tmppath}/%{name}-%{version}
BuildRequires: gcc
AutoReq: 0
Requires: qt5-qtwebengine qt5-qtbase qt5-qtbase-gui qt5-qtbase-common PyQt5 python3-qt5 python3-qt5-base python3-poppler-qt5 python3-qt5-webengine python3-pyqt5-sip
Requires(pre): qt5-qtwebkit python3-qt5-webkit
Requires(post): python3-pip libstdc++
Provides: arturium-browser webbrowser
AutoProv: 0
#
%description
Simple browser on PyQt5 and Bash

%define packagename arturium-browser
%define init "$(cat /proc/1/comm)"

%prep
%setup -q -n %{name}

%build
gcc opt/%{packagename}/%{packagename}.c -fPIC -lc -o %{name}
strip %{name}
cp %{name} %{packagename}

%check

%install
mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/share/{applications,metainfo,icons}
mkdir -p $RPM_BUILD_ROOT/usr/share/icons/hicolor/{512x512,256x256}/apps
mkdir -p $RPM_BUILD_ROOT/opt/%{packagename}/resources
install %{packagename} $RPM_BUILD_ROOT/usr/bin
install opt/%{packagename}/arturium.png $RPM_BUILD_ROOT/usr/share/icons/hicolor/512x512/apps
install opt/%{packagename}/usr/bin/arturium.png $RPM_BUILD_ROOT/usr/share/icons/hicolor/256x256/apps
install opt/%{packagename}/arturium.png $RPM_BUILD_ROOT/opt/%{packagename}
install %{name} $RPM_BUILD_ROOT/opt/%{packagename}
install opt/%{packagename}/usr/bin/plugin.py $RPM_BUILD_ROOT/opt/%{packagename}/resources
install opt/%{packagename}/%{packagename}.desktop $RPM_BUILD_ROOT/usr/share/applications
install opt/%{packagename}/%{packagename}.desktop $RPM_BUILD_ROOT/opt/%{packagename}
install opt/%{packagename}/usr/bin/product_logo_512.png $RPM_BUILD_ROOT/opt/%{packagename}
install opt/%{packagename}/usr/bin/product_logo_256.png $RPM_BUILD_ROOT/opt/%{packagename}
install opt/%{packagename}/usr/bin/resources/build_info.json $RPM_BUILD_ROOT/opt/%{packagename}/resources
install opt/%{packagename}/chromedriver $RPM_BUILD_ROOT/opt/%{packagename}
install opt/%{packagename}/usr/metainfo/%{packagename}.appdata.xml $RPM_BUILD_ROOT/usr/share/metainfo
install opt/%{packagename}/LICENSE.electron.txt $RPM_BUILD_ROOT/opt/%{packagename}

%files
%defattr(-,root,root)
/usr/share/applications/%{packagename}.desktop
/usr/share/icons/hicolor/{256x256,512x512}/apps/arturium.png
/opt/%{packagename}/
/usr/share/metainfo/%{packagename}.appdata.xml
/usr/bin/%{packagename}

%post
echo -n "  Configure %{init}: %{name}-%{version}-%{release}.x86_64"
sleep 1

%clean
rm -rf $RPM_BUILD_ROOT

%changelog
* Tue Jan 11 2023 %{name}
- Stable build
