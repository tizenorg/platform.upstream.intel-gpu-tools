Name:       intel-gpu-tools
Summary:    Diagnostic tools for Intel Integrated Graphics
Version:    1.7
Release:    0
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

%reconfigure \
    --disable-nouveau \
    --disable-static \
    --disable-tests

make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%make_install

%files
%license COPYING
%defattr(-,root,root,-)
%doc README
%{_bindir}/*
%doc %{_mandir}/man1/*.1.gz

