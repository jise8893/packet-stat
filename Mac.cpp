#include "Mac.h"

Mac::Mac(const std::string r) {
	unsigned int a, b, c, d, e, f;
	int res = sscanf_s(r.c_str(), "%02x:%02x:%02x:%02x:%02x:%02x", &a, &b, &c, &d, &e, &f);
	if (res != SIZE) {
		fprintf(stderr, "Mac sscanf return %d , %s", res, r.c_str());
		return;
	}

	mac_[0] = a;
	mac_[1] = b;
	mac_[2] = c;
	mac_[3] = d;
	mac_[4] = e;
	mac_[5] = f;
}
