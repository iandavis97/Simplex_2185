//https://www.gamedev.net/articles/programming/general-and-gameplay-programming/introduction-to-octrees-r3529/
#ifndef _MYOCTANT_
#define _MYOCTANT_
#include "Definitions.h"
#include "MyRigidBody.h"
#include "MyEntity.h"
namespace Simplex {
	class MyOctant
	{
		//items to insert into structure
		MyRigidBody* m_rigidBody;
		std::vector<MyEntity*>m_objects;

		static std::vector<MyEntity>m_pendingInsertion;

		//all posible child octants for this node in tree
		MyOctant* m_childNode[8];

		//indicating which child nodes are being used
		byte m_activeNodes = 0;

		//minimum size for enclosing region
		const int MIN_SIZE = 1;

		//how many frames we wait before deleting empty tree branch
		int m_maxLifeSpan = 8;
		int m_curLife = -1;//countdown time

		//reference to parent node
		MyOctant* m_parent;

		//tree has few objects that need to be inserted before it is complete
		const bool m_treeReady = false;
		const bool m_treeBuilt = false;//no pre-existing tree yet

		public:
			MyOctant();
			~MyOctant();
	};
}
#endif //_MYOCTANT_
