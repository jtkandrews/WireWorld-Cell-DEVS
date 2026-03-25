#include <iostream>
#include <string>
#include <memory>
#include <filesystem>
#include <cadmium/modeling/celldevs/grid/coupled.hpp>
#include <cadmium/simulation/logger/csv.hpp>
#include <cadmium/simulation/root_coordinator.hpp>
#include "wireworld_cell.hpp"

using namespace cadmium::celldevs;

std::shared_ptr<GridCell<wireworld_state, int>> addGridCell(const coordinates & cellId, const std::shared_ptr<const GridCellConfig<wireworld_state, int>>& cellConfig) {
    return std::make_shared<wireworld_cell>(cellId, cellConfig);
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_config.json>" << std::endl;
        return 1;
    }

    std::string configFilePath = argv[1];

    std::filesystem::path p(configFilePath);
    std::string base_name = p.stem().string(); 
    
    // Create logs dir
    std::string log_folder = "logs";
    if (!std::filesystem::exists(log_folder)) {
        std::filesystem::create_directory(log_folder);
    }

    std::string output_csv_name = log_folder + "/" + base_name + "_log.csv";

    auto model = std::make_shared<GridCellDEVSCoupled<wireworld_state, int>>("wireworld", addGridCell, configFilePath);
    model->buildModel();

    // Setup the simulation
    auto rootCoordinator = cadmium::RootCoordinator(model);
    
    // Set up logging
    rootCoordinator.setLogger<cadmium::CSVLogger>(output_csv_name, ";");
    
    // Run the simulation
    rootCoordinator.start();
    rootCoordinator.simulate(5000.0); 
    rootCoordinator.stop();

    return 0;
}
