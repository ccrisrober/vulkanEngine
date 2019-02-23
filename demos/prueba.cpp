#include <vulkanEngine/vulkanEngine.h>

int main( void )
{
  vulkanEngine::Foo f;
  f.hello( );

  try
  {
    std::vector<vk::LayerProperties> layerProps = vk::enumerateInstanceLayerProperties( );
    std::cout << "Layers: " << layerProps.size( ) << std::endl;
    uint32_t i = 0;
    for ( const auto& prop : layerProps )
    {
      std::cout << "Layer " << i << ":" << std::endl;
      std::cout << "\tlayerName             : " << prop.layerName << std::endl;
      std::cout << "\tspecVersion           : " << prop.specVersion << std::endl;
      std::cout << "\timplementationVersion : " << prop.implementationVersion << std::endl;
      std::cout << "\tdescription           : " << prop.description << std::endl;
      ++i;
    }
    std::vector<vk::ExtensionProperties> instanceExts = vk::enumerateInstanceExtensionProperties( );
    std::cout << "InstanceExtensions : " << instanceExts.size( ) << std::endl;
    for ( const auto& ext : instanceExts )
    {
      std::cout << "\t" << ext.extensionName << " (Version " << ext.specVersion << ")" << std::endl;
    }
  }
  catch ( std::system_error err )
  {
    std::cout << "System Error: " << err.what( ) << std::endl;
  }
  system( "PAUSE" );
  return 0;
}