AutoFloat
=========

A text format filter that adds an odd/even class to images or spans
(image + caption) to make them float alternately left and right.

Configurable:
- the starting side
- to exclude the module's CSS to use your theme's style.css
- to add classes to target a 'span', e.g. in case a caption is displayed
- to add classes to exclude a 'div', e.g. a set of thumbnails.


Example
-------

The filter turns:
  ‹img src="/path/photo.jpg"›
into:
  ‹img src="/path/photo.jpg" class="autofloat-odd"›


Features
--------

- Generates an organized layout of images in a text automatically.
- Easy for the less technical users.
- Saves time.
- Avoids inline styling.
- Inserting images later doesn't mess up the alternating floating.


Installation and configuration
------------------------------

Install this module using the official Backdrop CMS instructions at
https://backdropcms.org/guide/modules

Add the autofloat filter to one of your text formats under
'/admin/config/content/formats'. Put it below other image related filters in
the 'filter processing order'.

Configure under '/admin/config/content/autofloat'.

Re-save existing nodes you want to apply AutoFloat to. If you still can't see
any changes, try clearing both your site and browser cache as well.


Usage
-----

Images will float unless they have the class 'nofloat'.

A 'span' with the class 'float' will float the image and other containing
content, e.g. a caption under it.

Images in a 'div' with the class 'nofloat' do NOT float, e.g. a set of
thumbnails.

Avoid adding classes manually by defining classes added by other
modules/filters. Use your browser's inspector to find them.

The class 'nofloat' of a nested element has priority over classes set in the
parent, thus makes that the parent will not float.

Remember an element floats within the block-element containing it. If that
doesn't cover the full width, the image might not float as expected.
Check your CSS before submitting an issue.


CSS
---

The autofloat.css and autofloat-rtl.css files add a right-margin to left
floating images and a left-margin to right floating images.

If your images won't float your theme might not use the id or class "content"
to target the node body. Adjust the id or class used in the modules' css files
accordingly.

You can exclude the module's CSS on the configuration page to use your
customized theme's style.css.


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Maintainer
----------

- Martin Postma (https://github.com/lolandese)


