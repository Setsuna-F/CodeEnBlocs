#ifndef INPUTMODEL_HPP
#define INPUTMODEL_HPP

#include <string>
#include "blockcompositemodel.hpp"
#include "inputlistmodel.hpp"
#include "tools.h"

namespace satap{

	class InputModel : public BlockCompositeModel{

		public:
			InputModel();
			InputModel(InputListModel &inputList);

			void setInputList(InputListModel &inputList);
		virtual BlockModel* getBlockById(size_t id){
			std::cout<<"r0"<<std::endl;
			
			if (id==this->getId()){
				std::cout<<"r1"<<std::endl;
				return this;
			}
			std::cout<<"L'id"<<"="<<id<<std::endl;
			
			BlockModel *block=nullptr;
			/*for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
				std::cout<<(*it)->getId()<<"="<<id<<std::endl;
				
				if ((*it)->getId() == id){
			 std::cout<<"r2"<<std::endl;
			 return *it;
				}
				else{
			 std::cout<<"r3 "<< (*it)->strstr()<<std::endl;
			 block = (*it)->getBlockById(id);
				}
			 }*/
			std::cout<<"r4"<<std::endl;
			return block;
		}
			sct_type execute();
			typeBloc getType();
		private:
			InputListModel *_inputList; //TODO not inputlist but Game : then, game.getInputList().pop();

	};

}

#endif
