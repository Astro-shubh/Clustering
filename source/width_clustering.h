#ifndef WIDTH_CLUSTERING_H
#define WIDTH_CLUSTERING_H
#include "make_cartesian_clusters.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cfloat>
#include <bits/stdc++.h>
#include <algorithm>

class width_clustering{
        public:
                std::vector<double> Widths, X, Y, SNR;
                std::vector<make_cartesian_clusters::cluster> small_clusters;
                width_clustering(std::vector<double> X_locations, std::vector<double> Y_locations, std::vector<double> SNR, std::vector<double> Widths, std::vector<make_cartesian_clusters::cluster> input_clusters);
                void do_clustering();
                std::vector<std::vector<int>> final_clusters;
		std::vector<int> representative_elements;
        private:
                void get_representative();
		void connect_recursive(int idx);
		double distance(int idx1, int idx2);
                std::vector<int> list_labels;
		std::vector<int> connections;
		std::vector<int> status;
                void connect();
};
#endif
