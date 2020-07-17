"""     package.py

PACKAGE: Collection of modules grouped together
__INIT__.PY: if this file is present in directory python treats that directory as package.

CREATING PACKAGE:
sound_package
    |
    |__init__.py
    |format
        |__init__.py
        |wavread.py
        |wavwrite.py
    |effects
        |__init__.py
        |echo.py
            def fun(a):
            print(a)
    |filters
        |__init__.py
        |karaoke.py

 # mkdir sound_package
 # touch sound_package/__init__.py
 
 # mkdir -p sound_package/format
 # touch sound_package/format/__init__.py
 # touch sound_package/format/wavread.py
 # touch sound_package/format/wavwrite.py

 # mkdir -p sound_package/effects
 # touch sound_package/effects/__init__.py
 # touch sound_package/effects/echo.py

 # mkdir -p sound_package/filters
 # touch sound_package/filters/__init__.py
 # touch sound_package/filters/karaoke.py
 
 # vim sound_package_user.py

"""

from sound_package.effects.echo import fun
fun('Sit with ease, Preserve energy')   #Sit with ease, Preserve energy
