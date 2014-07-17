# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.11
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_chipset', [dirname(__file__)])
        except ImportError:
            import _chipset
            return _chipset
        if fp is not None:
            try:
                _mod = imp.load_module('_chipset', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _chipset = swig_import_helper()
    del swig_import_helper
else:
    import _chipset
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0



def is_sandybridge(*args):
  return _chipset.is_sandybridge(*args)
is_sandybridge = _chipset.is_sandybridge

def is_ivybridge(*args):
  return _chipset.is_ivybridge(*args)
is_ivybridge = _chipset.is_ivybridge

def is_valleyview(*args):
  return _chipset.is_valleyview(*args)
is_valleyview = _chipset.is_valleyview

def is_cherryview(*args):
  return _chipset.is_cherryview(*args)
is_cherryview = _chipset.is_cherryview

def is_haswell(*args):
  return _chipset.is_haswell(*args)
is_haswell = _chipset.is_haswell

def is_broadwell(*args):
  return _chipset.is_broadwell(*args)
is_broadwell = _chipset.is_broadwell

def intel_get_pci_device():
  return _chipset.intel_get_pci_device()
intel_get_pci_device = _chipset.intel_get_pci_device

def intel_register_access_init(*args):
  return _chipset.intel_register_access_init(*args)
intel_register_access_init = _chipset.intel_register_access_init

def intel_register_read(*args):
  return _chipset.intel_register_read(*args)
intel_register_read = _chipset.intel_register_read

def intel_register_write(*args):
  return _chipset.intel_register_write(*args)
intel_register_write = _chipset.intel_register_write

def intel_register_access_fini():
  return _chipset.intel_register_access_fini()
intel_register_access_fini = _chipset.intel_register_access_fini

def intel_register_access_needs_fakewake():
  return _chipset.intel_register_access_needs_fakewake()
intel_register_access_needs_fakewake = _chipset.intel_register_access_needs_fakewake

def pcidev_to_devid(*args):
  return _chipset.pcidev_to_devid(*args)
pcidev_to_devid = _chipset.pcidev_to_devid

def intel_dpio_reg_read(*args):
  return _chipset.intel_dpio_reg_read(*args)
intel_dpio_reg_read = _chipset.intel_dpio_reg_read

def intel_flisdsi_reg_read(*args):
  return _chipset.intel_flisdsi_reg_read(*args)
intel_flisdsi_reg_read = _chipset.intel_flisdsi_reg_read
# This file is compatible with both classic and new-style classes.


