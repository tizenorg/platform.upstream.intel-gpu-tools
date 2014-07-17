Name:       intel-gpu-tools
Summary:    Diagnositc tools for Intel Integrated Graphics
Version:    1.3
Release:    1
VCS:        git/xorg/app/intel-gpu-tools.git#intel-gpu-tools-1.3-1-g24e49c7
Group:      Development/Tools
License:    MIT
URL:        http://xorg.freedesktop.org/
Source0:    http://xorg.freedesktop.org/archive/individual/app/intel-gpu-tools-%{version}.tar.bz2
BuildRequires:  pkgconfig(libdrm_intel)
BuildRequires:  pkgconfig(pciaccess)
BuildRequires:  pkgconfig(xorg-macros)
BuildRequires:  pkgconfig(cairo)
BuildRequires:  pkgconfig(libudev)

%description
Description: %{summary}

%prep
%setup -q -n %{name}-%{version}

%build
%reconfigure --disable-static \
	--disable-nouveau
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install 

%files
%defattr(-,root,root,-)
%doc README
%{_bindir}/*
%doc %{_mandir}/man1/*.1.gz

