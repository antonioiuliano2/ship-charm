# SHiP-charm hit data analysis

This repository is dedicated to share analysis of the hits collected during the SHiP-charm measurement.

## Data format

The original data have been converted in a simple and accessible format. An `event` is defined by a trigger, and for each event `arrays` of hits are stored, containing the following information:

* Code for the subdetector the hit belongs to (1:Pixel, 2:SciFi, 3:Drift Tubes, 4:RPC);

* (x,y,z) position of the event;

* Detector ID from the original hit class;

* TrackID (when present, otherwise to be filled after tracking);

The dimension of the array is the number of hits from all the subdetectors, collected for that event.