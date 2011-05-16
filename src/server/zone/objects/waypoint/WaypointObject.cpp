/*
 *	server/zone/objects/waypoint/WaypointObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "WaypointObject.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"


// Imported class dependencies

#include "server/zone/objects/cell/CellObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/ZonePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/service/Message.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/login/account/Account.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/io/ObjectInputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/core/Task.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/city/CityManager.h"

#include "engine/util/Observer.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/Zone.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "system/lang/Time.h"

#include "server/zone/ZoneClientSession.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "system/net/Packet.h"

#include "engine/stm/TransactionalReference.h"

#include "system/net/SocketAddress.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "system/util/VectorMap.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "system/net/Socket.h"

#include "system/util/Vector.h"

/*
 *	WaypointObjectStub
 */

enum {RPC_SETCELLID__INT_,RPC_SETPLANETCRC__INT_,RPC_GETPLANETCRC__,RPC_SETCUSTOMNAME__UNICODESTRING_,RPC_GETCUSTOMNAME__,RPC_SETCOLOR__BYTE_,RPC_SETACTIVE__BYTE_,RPC_SETUNKNOWN__LONG_,RPC_SETSPECIALTYPEID__INT_,RPC_GETSPECIALTYPEID__,RPC_TOGGLESTATUS__,RPC_ISACTIVE__,RPC_GETCOLOR__};

WaypointObject::WaypointObject() : IntangibleObject(DummyConstructorParameter::instance()) {
	WaypointObjectImplementation* _implementation = new WaypointObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

WaypointObject::WaypointObject(DummyConstructorParameter* param) : IntangibleObject(param) {
}

WaypointObject::~WaypointObject() {
}


void WaypointObject::loadTemplateData(SharedObjectTemplate* templateData) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void WaypointObject::insertToMessage(BaseMessage* msg) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->insertToMessage(msg);
}

void WaypointObject::setCellID(unsigned int id) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCELLID__INT_);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setCellID(id);
}

void WaypointObject::setPlanetCRC(unsigned int crc) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPLANETCRC__INT_);
		method.addUnsignedIntParameter(crc);

		method.executeWithVoidReturn();
	} else
		_implementation->setPlanetCRC(crc);
}

unsigned int WaypointObject::getPlanetCRC() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLANETCRC__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getPlanetCRC();
}

void WaypointObject::setCustomName(const UnicodeString& name) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCUSTOMNAME__UNICODESTRING_);
		method.addUnicodeParameter(name);

		method.executeWithVoidReturn();
	} else
		_implementation->setCustomName(name);
}

UnicodeString WaypointObject::getCustomName() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCUSTOMNAME__);

		method.executeWithUnicodeReturn(_return_getCustomName);
		return _return_getCustomName;
	} else
		return _implementation->getCustomName();
}

void WaypointObject::setColor(byte newColor) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCOLOR__BYTE_);
		method.addByteParameter(newColor);

		method.executeWithVoidReturn();
	} else
		_implementation->setColor(newColor);
}

void WaypointObject::setActive(byte newStatus) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETACTIVE__BYTE_);
		method.addByteParameter(newStatus);

		method.executeWithVoidReturn();
	} else
		_implementation->setActive(newStatus);
}

void WaypointObject::setUnknown(unsigned long long id) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETUNKNOWN__LONG_);
		method.addUnsignedLongParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setUnknown(id);
}

void WaypointObject::setSpecialTypeID(int id) {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSPECIALTYPEID__INT_);
		method.addSignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setSpecialTypeID(id);
}

int WaypointObject::getSpecialTypeID() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSPECIALTYPEID__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getSpecialTypeID();
}

void WaypointObject::toggleStatus() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_TOGGLESTATUS__);

		method.executeWithVoidReturn();
	} else
		_implementation->toggleStatus();
}

bool WaypointObject::isActive() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISACTIVE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isActive();
}

byte WaypointObject::getColor() {
	WaypointObjectImplementation* _implementation = (WaypointObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCOLOR__);

		return method.executeWithByteReturn();
	} else
		return _implementation->getColor();
}

DistributedObjectServant* WaypointObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void WaypointObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<WaypointObjectImplementation*>(servant));
}

/*
 *	WaypointObjectImplementation
 */

WaypointObjectImplementation::WaypointObjectImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


WaypointObjectImplementation::~WaypointObjectImplementation() {
}


void WaypointObjectImplementation::finalize() {
}

void WaypointObjectImplementation::_initializeImplementation() {
	_setClassHelper(WaypointObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void WaypointObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (WaypointObject*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* WaypointObjectImplementation::_getStub() {
	return _this;
}

WaypointObjectImplementation::operator const WaypointObject*() {
	return _this;
}

Object* WaypointObjectImplementation::clone() {
	return dynamic_cast<Object*>(new WaypointObjectImplementation(*this));
}


void WaypointObjectImplementation::lock(bool doLock) {
}

void WaypointObjectImplementation::lock(ManagedObject* obj) {
}

void WaypointObjectImplementation::rlock(bool doLock) {
}

void WaypointObjectImplementation::wlock(bool doLock) {
}

void WaypointObjectImplementation::wlock(ManagedObject* obj) {
}

void WaypointObjectImplementation::unlock(bool doLock) {
}

void WaypointObjectImplementation::runlock(bool doLock) {
}

void WaypointObjectImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("WaypointObject");

}

void WaypointObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(WaypointObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool WaypointObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (IntangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "cellID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&cellID, stream);
		return true;
	}

	if (_name == "unknown") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&unknown, stream);
		return true;
	}

	if (_name == "planetCRC") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&planetCRC, stream);
		return true;
	}

	if (_name == "customName") {
		TypeInfo<UnicodeString >::parseFromBinaryStream(&customName, stream);
		return true;
	}

	if (_name == "color") {
		TypeInfo<byte >::parseFromBinaryStream(&color, stream);
		return true;
	}

	if (_name == "active") {
		TypeInfo<byte >::parseFromBinaryStream(&active, stream);
		return true;
	}

	if (_name == "specialTypeID") {
		TypeInfo<int >::parseFromBinaryStream(&specialTypeID, stream);
		return true;
	}


	return false;
}

void WaypointObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = WaypointObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int WaypointObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "cellID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&cellID, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "unknown";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned long long >::toBinaryStream(&unknown, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "planetCRC";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&planetCRC, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "customName";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<UnicodeString >::toBinaryStream(&customName, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "color";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<byte >::toBinaryStream(&color, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "active";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<byte >::toBinaryStream(&active, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "specialTypeID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&specialTypeID, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 7 + IntangibleObjectImplementation::writeObjectMembers(stream);
}

WaypointObjectImplementation::WaypointObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/waypoint/WaypointObject.idl():  		Logger.setLoggingName("WaypointObject");
	Logger::setLoggingName("WaypointObject");
}

void WaypointObjectImplementation::setCellID(unsigned int id) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		cellID = id;
	cellID = id;
}

void WaypointObjectImplementation::setPlanetCRC(unsigned int crc) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		planetCRC = crc;
	planetCRC = crc;
}

unsigned int WaypointObjectImplementation::getPlanetCRC() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		return planetCRC;
	return planetCRC;
}

void WaypointObjectImplementation::setCustomName(const UnicodeString& name) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		customName = name;
	customName = name;
}

UnicodeString WaypointObjectImplementation::getCustomName() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		return customName;
	return customName;
}

void WaypointObjectImplementation::setColor(byte newColor) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		color = newColor;
	color = newColor;
}

void WaypointObjectImplementation::setActive(byte newStatus) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		active = newStatus;
	active = newStatus;
}

void WaypointObjectImplementation::setUnknown(unsigned long long id) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		unknown = id;
	unknown = id;
}

void WaypointObjectImplementation::setSpecialTypeID(int id) {
	// server/zone/objects/waypoint/WaypointObject.idl():  		specialTypeID = id;
	specialTypeID = id;
}

int WaypointObjectImplementation::getSpecialTypeID() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		return specialTypeID;
	return specialTypeID;
}

void WaypointObjectImplementation::toggleStatus() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		active = !active;
	active = !active;
}

bool WaypointObjectImplementation::isActive() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		return active;
	return active;
}

byte WaypointObjectImplementation::getColor() {
	// server/zone/objects/waypoint/WaypointObject.idl():  		return color;
	return color;
}

/*
 *	WaypointObjectAdapter
 */

WaypointObjectAdapter::WaypointObjectAdapter(WaypointObjectImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* WaypointObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_SETCELLID__INT_:
		setCellID(inv->getUnsignedIntParameter());
		break;
	case RPC_SETPLANETCRC__INT_:
		setPlanetCRC(inv->getUnsignedIntParameter());
		break;
	case RPC_GETPLANETCRC__:
		resp->insertInt(getPlanetCRC());
		break;
	case RPC_SETCUSTOMNAME__UNICODESTRING_:
		setCustomName(inv->getUnicodeParameter(_param0_setCustomName__UnicodeString_));
		break;
	case RPC_GETCUSTOMNAME__:
		resp->insertUnicode(getCustomName());
		break;
	case RPC_SETCOLOR__BYTE_:
		setColor(inv->getByteParameter());
		break;
	case RPC_SETACTIVE__BYTE_:
		setActive(inv->getByteParameter());
		break;
	case RPC_SETUNKNOWN__LONG_:
		setUnknown(inv->getUnsignedLongParameter());
		break;
	case RPC_SETSPECIALTYPEID__INT_:
		setSpecialTypeID(inv->getSignedIntParameter());
		break;
	case RPC_GETSPECIALTYPEID__:
		resp->insertSignedInt(getSpecialTypeID());
		break;
	case RPC_TOGGLESTATUS__:
		toggleStatus();
		break;
	case RPC_ISACTIVE__:
		resp->insertBoolean(isActive());
		break;
	case RPC_GETCOLOR__:
		resp->insertByte(getColor());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WaypointObjectAdapter::setCellID(unsigned int id) {
	((WaypointObjectImplementation*) impl)->setCellID(id);
}

void WaypointObjectAdapter::setPlanetCRC(unsigned int crc) {
	((WaypointObjectImplementation*) impl)->setPlanetCRC(crc);
}

unsigned int WaypointObjectAdapter::getPlanetCRC() {
	return ((WaypointObjectImplementation*) impl)->getPlanetCRC();
}

void WaypointObjectAdapter::setCustomName(const UnicodeString& name) {
	((WaypointObjectImplementation*) impl)->setCustomName(name);
}

UnicodeString WaypointObjectAdapter::getCustomName() {
	return ((WaypointObjectImplementation*) impl)->getCustomName();
}

void WaypointObjectAdapter::setColor(byte newColor) {
	((WaypointObjectImplementation*) impl)->setColor(newColor);
}

void WaypointObjectAdapter::setActive(byte newStatus) {
	((WaypointObjectImplementation*) impl)->setActive(newStatus);
}

void WaypointObjectAdapter::setUnknown(unsigned long long id) {
	((WaypointObjectImplementation*) impl)->setUnknown(id);
}

void WaypointObjectAdapter::setSpecialTypeID(int id) {
	((WaypointObjectImplementation*) impl)->setSpecialTypeID(id);
}

int WaypointObjectAdapter::getSpecialTypeID() {
	return ((WaypointObjectImplementation*) impl)->getSpecialTypeID();
}

void WaypointObjectAdapter::toggleStatus() {
	((WaypointObjectImplementation*) impl)->toggleStatus();
}

bool WaypointObjectAdapter::isActive() {
	return ((WaypointObjectImplementation*) impl)->isActive();
}

byte WaypointObjectAdapter::getColor() {
	return ((WaypointObjectImplementation*) impl)->getColor();
}

/*
 *	WaypointObjectHelper
 */

WaypointObjectHelper* WaypointObjectHelper::staticInitializer = WaypointObjectHelper::instance();

WaypointObjectHelper::WaypointObjectHelper() {
	className = "WaypointObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void WaypointObjectHelper::finalizeHelper() {
	WaypointObjectHelper::finalize();
}

DistributedObject* WaypointObjectHelper::instantiateObject() {
	return new WaypointObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* WaypointObjectHelper::instantiateServant() {
	return new WaypointObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* WaypointObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new WaypointObjectAdapter((WaypointObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

