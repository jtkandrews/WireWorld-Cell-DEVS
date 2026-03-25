#ifndef WIREWORLD_CELL_HPP
#define WIREWORLD_CELL_HPP

#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <cadmium/modeling/celldevs/grid/config.hpp>
#include <iostream>

using namespace cadmium::celldevs;

// State Struct
struct wireworld_state {
    int state_val;
    wireworld_state() : state_val(0) {}
    wireworld_state(int v) : state_val(v) {}
};

inline void from_json(const nlohmann::json& j, wireworld_state& s) {
    j.at("state_val").get_to(s.state_val);
}


inline std::ostream& operator<<(std::ostream& os, const wireworld_state& st) {
    os << "<" << st.state_val << ">";
    return os;
}


inline bool operator!=(const wireworld_state& a, const wireworld_state& b) {
    return a.state_val != b.state_val;
}

class wireworld_cell : public GridCell<wireworld_state, int> {
public:
    wireworld_cell(const coordinates& id, const std::shared_ptr<const GridCellConfig<wireworld_state, int>>& config)
        : GridCell<wireworld_state, int>(id, config) {}

    [[nodiscard]] wireworld_state localComputation(wireworld_state state,
          const std::unordered_map<coordinates, NeighborData<wireworld_state, int>>& neighborhood) const override {
        
        wireworld_state next_state = state;

        // Count how many neighbors are Electron Heads
        int head_count = 0;
        for (const auto& [neighborId, neighborData] : neighborhood) {
            if (neighborData.state->state_val == 1) {
                head_count++;
            }
        }

        // WireWorld Rules
        if (state.state_val == 0) {
            next_state.state_val = 0;
        } 
        else if (state.state_val == 1) {
            next_state.state_val = 2;
        } 
        else if (state.state_val == 2) {
            next_state.state_val = 3;
        } 
        else if (state.state_val == 3) {
            if (head_count == 1 || head_count == 2) {
                next_state.state_val = 1;
            } else {
                next_state.state_val = 3;
            }
        }

        return next_state;
    }

    [[nodiscard]] double outputDelay(const wireworld_state& state) const override {
        return 100.0;
    }
};

#endif
