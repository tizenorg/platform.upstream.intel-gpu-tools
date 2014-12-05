Name:       intel-gpu-tools
Summary:    Diagnostic tools for Intel Integrated Graphics
Version:    1.8
Release:    0
Group:      Development/Tools
License:    MIT
URL:        http://xorg.freedesktop.org/
#X-Vc-Url:  git://anongit.freedesktop.org/xorg/app/intel-gpu-tools
ExclusiveArch:  %ix86 x86_64
Source0:    http://xorg.freedesktop.org/archive/individual/app/intel-gpu-tools-%{version}.tar.bz2
BuildRequires:  pkgconfig(libdrm_intel)
BuildRequires:  pkgconfig(pciaccess)
BuildRequires:  pkgconfig(xorg-macros)
BuildRequires:  pkgconfig(cairo)
BuildRequires:  pkgconfig(libudev)
BuildRequires:  gtk-doc
BuildRequires:  gnome-common


%description
Description: %{summary}

%prep
%setup -q -n %{name}-%{version}

%build

%autogen

%reconfigure \
    --disable-nouveau \
    --disable-static \
    --disable-tests \
    --disable-gtk-doc

%__make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%make_install

%files
%license COPYING
%defattr(-,root,root,-)
%doc README
%{_bindir}/*
%doc %{_mandir}/man1/*.1.gz

