QDiffView
=================================

Diff view widget like GitHub.

.. image:: https://raw.githubusercontent.com/qtpm/QDiffView/master/diff.png

Install
--------------

This is a `qtpm <https://github.com/qtpm/qtpm>`_ package.

.. code-block:: bash

   $ qtpm get github.com/qtpm/qdiffview

Headers and a library file are installed under ``vendor`` directory.

Example
--------------

.. code-block:: cpp

   #include <iostream>
   #include <qdiffview/qdiffview.h>


   int main(int argc, char **argv)
   {
       QApplication app(argc, argv);

       qdiffview::QDiffView *view = new qdiffview::QDiffView();
       view->setSource(oldSource, newSource);
       view->show();

       return app.exec();
   }

Reference
--------------

qdiffview::QDiffView class
~~~~~~~~~~~~~~~~~~~~~~~~~~

**void setSource(const QString& oldSource, const QString& newSource)**

  Set text data to show diff.

Develop
--------------

``qtpm`` command helps your development.

.. code-block:: bash

   $ git clone git@github.com:shibukawa.yoshiki/qdiffview.git
   $ cd qdiffview

   # Run the following command once if this package has required packages
   # -u updates modules they are already downloaded
   $ qtpm get [-u]

   # Build and run test
   $ qtpm test

   # Try install to ``vendor`` folder
   $ qtpm build


Folder Structure and Naming Convention
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: none

   + src/           // Header files under this folder will be published.
   |  |             // Don't add `main.cpp`. qtpm assumes this package is an application, not library.
   |  + private/    // Files under this folder will hide from outer modules.
   + translations/  // .ts files (use `qtpm i18n` commands)
   + qtresources/   // Files that are listed in resource.qrc and linked to application.
   + examples/      // Each .cpp file is build into executable.
   + test/          // Each _test.cpp file is built into executable and launched by qtpm test.
   |                // Use `qtpm add test`` to add test case.
   |                // Other .cpp files are used as utility code. They are linked to test modules.
   + build-*/       // Work folder.
   + CMakeExtra.txt // This file is included from created CMakeLists.txt.
                    // You can add any extra build options here.

Author
--------------

* Yoshiki Shibukawa

License
--------------

The MIT License (MIT)

It uses `Diff template library <https://github.com/cubicdaiya/dtl>`_ by @cubicdaiya. It is under BSD license.

History
--------------

* 08/26/2016: First version.
