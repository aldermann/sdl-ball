//
// Created by Trần Công Việt An on 6/5/20.
//

#pragma once
#include <boost/filesystem/path.hpp>

void disable_compositor();
double signum(double);
bool doubleEqual(const double &a, const double &b);
boost::filesystem::path getParentPath(const boost::filesystem::path &p);
