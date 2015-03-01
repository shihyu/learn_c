# ASLTegra
ASLTegra is a Sign Language translator for the NVidia Jetson TK1, written
using [OpenCV](http://opencv.org/).  It currently translates letters only.

## About
More generally, this program reads from a video stream (e.g. webcam) and
matches them to a set of reference images.

## Controls
 * To create a reference image, press any `letter key` on the keyboard for the image
to map to.  This will create (and overwrite) the corresponding image in the
`images/` directory.
 * To reset the base background, press `space`.
 * To exit, press `esc`.

## Scripts
All non-repeated characters are sent to the `doSystemCalls` function in
`scripts.cpp`, which can be used to execute user-defined scripts.

## Credits
This software was created by Ethan Gordon ([@egordon](https://github.com/egordon)),
Davis Liu ([@liuquinlin](https://github.com/liuquinlin)), and Jeffrey Han
([@itdelatrisu](https://github.com/itdelatrisu)) during HackPrinceton Fall 2014.

## License
**This software is licensed under the MIT license.**
You can find the full text of the license [here](LICENSE).
